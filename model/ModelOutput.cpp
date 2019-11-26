#include "ModelOutput.h"

using namespace std;
using namespace cv;
using namespace dnn;

class ModelOutput
{
private:
    float confThreshold = 0.5;
    float nmsThreshold = 0.4;
    int inpWidth = 416;
    int inpHeight = 416;
    string classesFile = "coco.names";
    vector<string> classes;

public:
    ModelOutput(/* args */);
    ~ModelOutput();
};

ModelOutput::ModelOutput(/* args */)
{
    ifstream ifs((this->classesFile).c_str());
    string line;
    while (getline(ifs, line))
    {
        (this->classes).push_back(line);
    }
    string modelConfiguration = "/yolo/yolov3-tiny.cfg";
    string modelWeights = "yolov3-tiny.weights";

    //Network
    Net net = readNetFromDarknet(modelConfiguration, modelWeights);
    net.setPreferableBackend(DNN_BACKEND_OPENCV);
    net.setPreferableTarget(DNN_TARGET_CPU);

    string str, outputFile;
    Mat frame, blob;

    while (waitkey(1) < 0)
    {
        frame = imread("./test.jpg");
        if (!(frame.empty()))
        {
            outputFile = "outFile.jpg";
            blobFromImage(frame, blob, 1 / 255.0, cvSize(this->inpWidth, this->Height), Scalar(0, 0, 0), true, false);
            net.setInput(blob);
            vector<Mat> outs;
            net.forward(outs, getOutputNames(net));
            postprocess(frame, outs);

            vector<double> layersTimes;
            double freq = getTickFrequency() / 1000;
            double t = net.getPerfProfile(layersTimes) / freq;
            string label = format("Inference time for a frame: %.2f ms", t);
            putText(frame, label, Point(0, 15)), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 255));

            Mat detectedFrame;
            frame.convertTo(detectedFrame, CV_8U);
            imwrite(outputFile, detectedFrame);
        }
    }
}

ModelOutput::~ModelOutput()
{
}

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
            if (confidence > confThreshold)
            {
                int centerX = (int)(data[0] * frame.cols);
                int centerY = (int)(data[1] * frame.rows);
                int width = (int)(data[2] * frame.cols);
                int height = (int)(data[3] * frame.rows);
                int left = centerX - width / 2;
                int top = centerY - height / 2;

                classIds.push_back(classIdPoint.x);
                confidences.push_back((float)confidence);
                boxes.push_back(Rect(left, top, width, height));
            }
        }
    }