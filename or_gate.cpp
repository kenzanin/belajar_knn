#include <iostream>

#include "KNNClassifier.h"

const int input = 2;
const int classes = 2;

enum __CLASSES__ { FALSE = 0, TRUE };

const float dataset_true[][2] = {
    {0, 1},
    {1, 0},
    {1, 1},
};
const float dataset_false[][2] = {
    {0, 0},
};

int main(int, char **) {
  KNNClassifier myKnn(input);

  for (int i = 0; i < sizeof(dataset_false) / sizeof(dataset_false[0]); i++) {
    myKnn.addExample(dataset_false[i], FALSE);
  }
  for (int i = 0; i < sizeof(dataset_true) / sizeof(dataset_true[0]); i++) {
    myKnn.addExample(dataset_true[i], TRUE);
  }

  const char *label[] = {"FALSE", "TRUE"};

  float in[input] = {0, 0};
  int result = myKnn.classify(in, 1);
  std::printf("input: %d , %d output: %s\n", static_cast<int>(in[0]),
              static_cast<int>(in[1]), label[result]);

  in[0] = 0;
  in[1] = 1;
  result = myKnn.classify(in, 1);
  std::printf("input: %d , %d output: %s\n", static_cast<int>(in[0]),
              static_cast<int>(in[1]), label[result]);

  in[0] = 1;
  in[1] = 0;
  result = myKnn.classify(in, 1);
  std::printf("input: %d , %d output: %s\n", static_cast<int>(in[0]),
              static_cast<int>(in[1]), label[result]);

  in[0] = 1;
  in[1] = 1;
  result = myKnn.classify(in, 1);
  std::printf("input: %d , %d output: %s\n", static_cast<int>(in[0]),
              static_cast<int>(in[1]), label[result]);
}
