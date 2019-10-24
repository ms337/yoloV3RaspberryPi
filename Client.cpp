#include <opencv/cv.h>
#include <opencv2/highgui/highui.hpp>

using namespace std;
using namespace cv;

int main() {
    VideoCapture cap(0);
    if (!capisOpened()) {
        cout << "Change the camera port number";
        return -1;
    }
    while(true) {
        Mat frame;
        cap.read(frame);
        imshow("camera", frame);
        if(waitKey(30) == 27) {
            return 0;
        }
    }
}