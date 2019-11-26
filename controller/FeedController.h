#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <thread>

class FeedController
{
private:
    cv::VideoCapture feedCV;
    std::thread *internalThread;

public:
    FeedController(/* args */);
    ~FeedController();
    void getFeed();
    void updateFeedThread();
};