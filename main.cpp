// Copyright 2023
#include <Arduino_KNN.h>

#include <cstdio>
#include <iostream>
#include <string>

const int RGB = 3;
const int input = RGB;  // R, G, B
const int classes = 3;  // RED, ORANGE, YELLOW

constexpr float example_red[][RGB] = {
    {255, 0, 0},    // Fire engine red
    {255, 64, 0},   // Red orange
    {255, 128, 0},  // Pumkin Orange
};
constexpr float example_orange[][RGB] = {
    {229, 107, 26},  // Rusty orange
    {229, 158, 26},  // Squash
    {229, 209, 26},  // ugly yellow
};
constexpr float example_yellow[][RGB] = {
    {225, 255, 0},  // Yellow
    {191, 255, 0},  // Yellow Green
    {127, 255, 3},  // Bright lime
};

enum __CLASSES { RED = 0, ORANGE, YELLLOW };
const int K = 5;  // This example uses a case of k-Nearest Neighbour (KNN)
                  // algorithm where k=5.

int main(int, char **) {
  auto colorNormalize = [](const float input[RGB], float output[RGB]) -> void {
    const float total = (input[0] + input[1] + input[2]) * 1.0;
    output[0] = input[0] / total;
    output[1] = input[1] / total;
    output[2] = input[2] / total;
  };

  KNNClassifier myKNN(input);
  for (int i = 0; i < sizeof(example_red) / sizeof(example_red[0]); i++) {
    float tmp[RGB] = {};
    colorNormalize(example_red[i], tmp);
    myKNN.addExample(tmp, RED);
  }

  for (int i = 0; i < sizeof(example_orange) / sizeof(example_orange[0]); i++) {
    float tmp[RGB] = {};
    colorNormalize(example_orange[i], tmp);
    myKNN.addExample(tmp, ORANGE);
  }

  for (int i = 0; i < sizeof(example_yellow) / sizeof(example_yellow[0]); i++) {
    float tmp[RGB] = {};
    colorNormalize(example_yellow[i], tmp);
    myKNN.addExample(tmp, YELLLOW);
  }

  std::printf(
      "knn count %d, class red count %d,  orange count %d, class yellow "
      "count %d\n",
      myKNN.getCount(), myKNN.getCountByClass(RED),
      myKNN.getCountByClass(ORANGE), myKNN.getCountByClass(YELLLOW));

  const char *label[classes] = {"red", "orange", "yellow"};

  float colors[input] = {127, 255, 30};
  std::printf("Color input: %.2f, %.2f, %.2f\n", colors[0], colors[1],
              colors[2]);
  colorNormalize(colors, colors);
  std::printf("normalize: %f, %f, %f\n", colors[0], colors[1], colors[2]);
  const int result = myKNN.classify(colors, K);

  std::cout << "result is: " << label[result] << std::endl;
}
