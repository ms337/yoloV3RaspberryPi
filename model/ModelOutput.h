/*!
   \file ModelOutput.h
   \brief header file for modelouput.cpp
   \author team9
*/
#ifndef MODEL_OUTPUT
#define MODEL_OUTPUT
//header file for ModelOutput
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/types_c.h>
#include <tuple>

class ModelOutput
{
private:
  float confThreshold;
  float nmsThreshold;
  int inpWidth;
  int inpHeight;
  std::string classesFile;
  std::vector<std::string> classes;
  std::vector<std::tuple<int, int, int>> classesAndMidpoints;

  std::string line;

  std::string modelConfiguration;
  std::string modelWeights;

  //Network
  cv::dnn::Net net;

public:
  ModelOutput();
  ~ModelOutput();
  void run(cv::Mat inpFrame, cv::Mat *outFrame);
  std::vector<std::string> getOutputsNames(const cv::dnn::Net &net);
  void postprocess(cv::Mat &frame, const std::vector<cv::Mat> &outs);
  void drawPred(int classId, float conf, int left, int top, int right, int bottom, cv::Mat &frame);
  std::vector<std::tuple<int, int, int>> getClassesAndMidpoints();
};

#endif
