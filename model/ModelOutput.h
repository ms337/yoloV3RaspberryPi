#ifndef MODEL_OUTPUT
#define MODEL_OUTPUT

#include <string>
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
#include <opencv2/dnn/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/types_c.h>

class ModelOutput
{
private:
  float confThreshold;
  float nmsThreshold;
  int inpWidth;
  int inpHeight;
  std::string classesFile;
  std::vector<std::string> classes;

public:
  ModelOutput();
  ~ModelOutput();
  std::vector<std::string> getOutputsNames(const cv::dnn::Net &net);
  void postprocess(cv::Mat &frame, const std::vector<cv::Mat> &outs);
  void drawPred(int classId, float conf, int left, int top, int right, int bottom, cv::Mat &frame);
};

#endif