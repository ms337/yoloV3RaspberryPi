#include <string>
#include <opencv2/opencv.hpp >
#include <vector>
#include <iostream>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>

class ModelOutput
{
private:
  float confThreshold;
  float nmsThreshold;
  int inpWidth;
  int inpHeight;
  string classesFile;
  vector<string> classes;
public:
    ModelOutput(/* args */);
    ~ModelOutput();
    (Mat &frame, const vector<Mat> &outs)
    void postprocess(Mat& frame, const vector<Mat>& outs);
    NMSBoxes(boxes, confidences, confThreshold, nmsThreshold, indices);
    void drawPred(int classId, float conf, int left, int top, int right, int bottom, Mat& frame);
    vector<String> getOutputsNames(const Net& net);
};
