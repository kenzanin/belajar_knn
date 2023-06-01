#include "Arduino_KNN.h"

#include "KNNClassifier.h"
#include "iostream"
#include <cstdio>

const int input = 1;
const int classes = 3;

const float class_one[]{1, 3};
const float class_four[]{4, 6};
const float class_seven[]{7, 9};

int main() {
  KNNClassifier myKnn(input);

  myKnn.addExample(class_one, 1);
  myKnn.addExample(class_four, 4);
  myKnn.addExample(class_seven, 7);

  const float test[]{8};
  int result = myKnn.classify(test, 1);
  std::printf("result is: %d\n", result);
}