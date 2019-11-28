#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <thread>

class FeedController
{
private:
    cv::VideoCapture feedCV;
    std::thread *internalThread;
    cv::Mat frame;
    cv::Mat outFrame;

public:
    FeedController(/* args */);
    ~FeedController();
    cv::Mat getFeed();
    void updateFeedThread();
};
