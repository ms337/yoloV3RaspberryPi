/**
 * @file FeedConstroller.cpp
 * @author team9
 * @brief used to view the webcam
 */

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <thread>
#include "FeedController.h"
#include "../model/ModelOutput.h"

using namespace std;
using namespace cv;
/*!
   \brief constructor to create a feed controller. This holds the information passed to the database
*/
FeedController::FeedController()
{
    VideoCapture feedCV;
    Mat frame;
    Mat outFrame;
    Zone zones[30];
    zonesDefinedCount;

    for (int i = 0; i < 10; i++)
    {
        this->classesOfObjsSelected[i] = -1;
    }

    //
    internalThread = new thread(&FeedController::updateFeedThread, this);
    currentZoneIndex = -1;
    string objects[80] = {"person", "bicycle", "car", "motorcycle", "airplane", "bus", "train", "truck", "boat", "traffic light", "fire hydrant", "stop_sign", "parking meter", "bench", "bird", "cat", "dog", "horse", "sheep", "cow", "elephant", "bear", "zebra", "giraffe", "backpack", "umbrella", "handbag", "tie", "suitcase", "frisbee", "skis", "snowboard", "sports ball", "kite", "baseball bat", "baseball glove", "skateboard", "surfboard", "tennis racket", "bottle", "wine glass", "cup", "fork", "knife", "spoon", "bowl", "banana", "apple", "sandwich", "orange", "broccoli", "carrot", "hot dog", "pizza", "doughnut", "cake", "chair", "couch", "potted plant", "bed", "dining table", "toilet", "tv", "laptop", "mouse", "remote", "keyboard", "cell phone", "microwave", "oven", "toaster", "sink", "refrigerator", "book", "clock", "vase", "scissors", "teddy bear", "hair dryer", "toothbrush"};
}
/*!
   \brief deconstructor
*/
FeedController::~FeedController()
{
    // internalThread->interrupt();
    std::cout << "hey" << std::endl;
    internalThread->join();
}
/*!
   \brief getter method to return feed ie. the current frame on the webcame
   \return frame of current feed
*/
cv::Mat FeedController::getFeed()
{
    return this->outFrame;
}
/*!
   \brief manages the tiny yolo model and displays it
*/
void FeedController::updateFeedThread()
{

    if (!feedCV.open(0))
        exit(-1);

    ModelOutput model = ModelOutput();
    this->dbWriter = DatabaseWriter::getInstance();

    int frameCount = 0;
    //threaded to output the webcam, hence the infinite loop
    for (;;)
    {
        feedCV >> this->frame;
        // calls tiny yolo to run its model
        model.run(this->frame, &(this->outFrame));
        //output data to database every second/30 frames
        if (frameCount == 30)
        {
            vector<tuple<int, int, int>> listOfClassesFound = model.getClassesAndMidpoints();
<<<<<<< HEAD
            dbWriter.write(listOfClassesFound, this->zones, this->classesOfObjsSelected);
=======
            dbWriter->write(listOfClassesFound, this->zones, this->classesOfObjsSelected);
            // cout << "----------" << endl;
            // for (auto x : listOfClassesFound)
            // {
            //     cout << "tuples:" << endl;
            //     cout << "Id: " << get<0>(x) << "X, Y: " << get<1>(x) << ", " << get<2>(x) << endl;
            // }
            // cout << "----------" << endl;
>>>>>>> 2dab7a878cb3e4981dea2138bdd0e3cd8a0be885
            frameCount = 0;
        }
        frameCount++;
    }
}
/*!
   \brief Used to add all of the zones to a list
   \param an array of 8 numbers representing the 4 coordinates in one zone
*/
void FeedController::createZones(int array[8])
{
    this->currentZoneIndex++;
    Zone zone = Zone(array, to_string(this->currentZoneIndex + 1));
    if (this->currentZoneIndex >= 30)
    {
        cerr << "Max limit of 30 Zones reached. Cannot add any more zones." << endl;
    }
    this->zones[this->currentZoneIndex] = zone;
}
/*!
   \brief Used to add all of the objects that the user wants to see to a list
   \param an array of 10 integers which corresponds to the id of the object slected by the user

*/
void FeedController::getObjectsSelected(int objectsSelected[10])
{

    for (int i = 0; i < 10; i++)
    {
        cout << "ObjectLabelNo: " << objectsSelected[i] << endl;
        this->classesOfObjsSelected[i] = objectsSelected[i];
    }
}
/*!
   \brief getter method to return the array of all objects defined by tiny yolov3
   \return string array of size 80
*/
string *FeedController::getObjectsAvailable()
{
    return this->objects;
}

void FeedController::setZonesCount(int zoneCount)
{
    this->zonesDefinedCount = zoneCount;
    cout << "FEEDC NZOMES: " << endl;
    cout << this->zonesDefinedCount << endl;
    this->dbWriter->setNZones(zoneCount);
}