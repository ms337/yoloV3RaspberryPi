/*!
   \file ModelOutput.cpp
   \brief Runs tiny yolov3 model
   \author team9
*/
#include "ModelOutput.h"

using namespace cv;
using namespace dnn;
using namespace std;
/*!
   \brief constructor for the model
*/
ModelOutput::ModelOutput()
{
    //initialize the parameters
    confThreshold = 0.3;
    nmsThreshold = 0.3;
    inpWidth = 416;
    inpHeight = 416;
    //loads name of classes
    classesFile = "/Users/msinghal/team9/model/yolo/coco.names";
    classes;

    classesAndMidpoints;

    ifstream ifs(classesFile.c_str());
    line;
    while (getline(ifs, line))
    {
        classes.push_back(line);
    }

    //give configuration and weight files of the model
    modelConfiguration = "/Users/msinghal/team9/model/yolo/yolov3-tiny.cfg";
    modelWeights = "/Users/msinghal/team9/model/yolo/yolov3-tiny.weights";

    //load the Network using the configuration files
    net = readNetFromDarknet(modelConfiguration, modelWeights);
    net.setPreferableBackend(DNN_BACKEND_OPENCV);
    net.setPreferableTarget(DNN_TARGET_CPU);
}
/*!
   \brief deconstructor for the model
*/
ModelOutput::~ModelOutput()
{
}
/*!
   \brief runs the model
   \param input frame is a stillframe of what is displayed on the webcam, and converts to something readable by model
*/
void ModelOutput::run(Mat inpFrame, Mat *outFrame)
{
    string str, outputFile;
    Mat frame, blob;
    frame = inpFrame;
    //check to make sure frame is not empty
    if (!(frame.empty()))
    {
        this->classesAndMidpoints.clear();
        //create a 4d blob form the frame passed
        blobFromImage(frame, blob, 1 / 255.0, CvSize(this->inpWidth, this->inpHeight), Scalar(0, 0, 0), true, false);
        //set the input blob to the network
        net.setInput(blob);
        // forward pass the vector outs to get output of the output layers
        vector<Mat> outs;
        net.forward(outs, ModelOutput::getOutputsNames(this->net));
        //remove incorrect bounding boxes due to their low confidence on object detection
        ModelOutput::postprocess(frame, outs);
        // create vector of type double to hold layers Times
        vector<double> layersTimes;
        //get overall time for inference and timings for each of the layers
        double freq = getTickFrequency() / 1000;
        double t = (this->net).getPerfProfile(layersTimes) / freq;
        //wirte the frame with detection boxes
        string label = format("Inference time for a frame: %.2f ms", t);
        putText(frame, label, Point(0, 15), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 255));

        frame.convertTo(*outFrame, CV_8U);
    }
}
/*!
   \brief converts numberical values of objects into names
   \param a layer of all objects on a frame
   \return a vector of the string values of the names of objects
*/
vector<String> ModelOutput::getOutputsNames(const Net &net)
{
    static vector<String> names;
    if (names.empty())
    {
        //Get the indices of the output layers, i.e. the layers with unconnected outputs
        vector<int> outLayers = (this->net).getUnconnectedOutLayers();

        //get the names of all the layers in the network
        vector<string> layersNames = (this->net).getLayerNames();

        // Get the names of the output layers in names
        names.resize(outLayers.size());
        for (size_t i = 0; i < outLayers.size(); ++i)
            names[i] = layersNames[outLayers[i] - 1];
    }
    return names;
}

//Credit goes to author of the below repository
//from https://github.com/spmallick/learnopencv/blob/master/ObjectDetection-YOLO/object_detection_yolo.cpp?fbclid=IwAR0G5mEa0KPaGdlyCkHcrm9o1cfd1I6YfyOBurblL0CF52HP6ZmDxcFnAf8
/*!
   \brief processes the various outputs of the model
   \param takes a frame that allows it to later draw on a prediction box, and the output of all the detected objects
*/
void ModelOutput::postprocess(Mat &frame, const vector<Mat> &outs)
{
    vector<int> classIds;
    vector<float> confidences;
    vector<Rect> boxes;

    for (size_t i = 0; i < outs.size(); ++i)
    {
        // Scan through all the bounding boxes output from the network and keep only the
        // ones with high confidence scores. Assign the box's class label as the class
        // with the highest score for the box.
        float *data = (float *)outs[i].data;
        for (int j = 0; j < outs[i].rows; ++j, data += outs[i].cols)
        {
            Mat scores = outs[i].row(j).colRange(5, outs[i].cols);
            Point classIdPoint;
            double confidence;
            // Get the value and location of the maximum score
            minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
            if (confidence > this->confThreshold)
            {
                //Midpoint
                int centerX = (int)(data[0] * frame.cols);
                int centerY = (int)(data[1] * frame.rows);
                int width = (int)(data[2] * frame.cols);
                int height = (int)(data[3] * frame.rows);
                int left = centerX - width / 2;
                int top = centerY - height / 2;

                classIds.push_back(classIdPoint.x);
                confidences.push_back((float)confidence);
                boxes.push_back(Rect(left, top, width, height));
                tuple<int, int, int> entry;
                entry = make_tuple(classIdPoint.x, centerX, centerY);
                this->classesAndMidpoints.push_back(entry);
            }
        }
    }

    // Perform non maximum suppression to eliminate redundant overlapping boxes with lower confidences
    vector<int> indices;
    NMSBoxes(boxes, confidences, this->confThreshold, this->nmsThreshold, indices);
    for (size_t i = 0; i < indices.size(); ++i)
    {
        int idx = indices[i];
        Rect box = boxes[idx];
        drawPred(classIds[idx], confidences[idx], box.x, box.y,
                 box.x + box.width, box.y + box.height, frame);
    }
}
/*!
   \brief draws a bounding box for a prediction
   \param classID, conf, left, top, right, and bottom are used to determine dimensions of the boudning box. bounding box drawn on the frame
*/
void ModelOutput::drawPred(int classId, float conf, int left, int top, int right, int bottom, Mat &frame)
{
    //Draw a rectangle displaying the bounding box
    rectangle(frame, Point(left, top), Point(right, bottom), Scalar(255, 178, 50), 3);

    //Get the label for the class name and its confidence
    string label = format("%.2f", conf);
    if (!(this->classes).empty())
    {
        CV_Assert(classId < (int)(this->classes).size());
        label = (this->classes)[classId] + ":" + label;
    }

    //Display the label at the top of the bounding box
    int baseLine;
    Size labelSize = getTextSize(label, FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
    top = max(top, labelSize.height);
    rectangle(frame, Point(left, top - round(1.5 * labelSize.height)), Point(left + round(1.5 * labelSize.width), top + baseLine), Scalar(255, 255, 255), FILLED);
    putText(frame, label, Point(left, top), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 0, 0), 1);
}
/*!
   \brief creates a vector to be saved into the database
   \return vector of type tuple. the 3 parts of the tuple are classID, x, y
*/
vector<tuple<int, int, int>> ModelOutput::getClassesAndMidpoints()
{
    return this->classesAndMidpoints;
}
