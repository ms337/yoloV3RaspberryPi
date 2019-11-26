#include <iostream>
using namespace std;
class objectList{

  int i=0;
  string object[80] = {"person", "bicycle" ,"car","motorcycle","airplane","bus","train","truck","boat","traffic light","fire hydrant","stop_sign","parking meter","bench","bird","cat","dog","horse","sheep","cow","elephant","bear","zebra","giraffe","backpack","umbrella","handbag","tie","suitcase","frisbee","skis","snowboard","sports ball","kite","baseball bat","baseball glove","skateboard","surfboard","tennis racket","bottle","wine glass","cup","fork","knife","spoon","bowl","banana","apple","sandwich","orange","broccoli","carrot","hot dog","pizza","doughnut","cake","chair","couch","potted plant","bed","dining table","toilet","tv","laptop","mouse","remote","keyboard","cell phone","microwave","oven","toaster","sink","refrigerator","book","clock","vase","scissors","teddy bear","hair dryer","toothbrush"};

  string selectedObjects[4];

  string getObject(string item){
    int j=0;
    while (item.compare(object[j]) != 0){
      j=j+1;
    }
    return object[j];
  }

  void addObject(string item){
    selectedObjects[i]= item;
    i=i+1;
  }
};
