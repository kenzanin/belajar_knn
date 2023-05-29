cmake_minimum_required(VERSION 3.0.0)
project(
  coba02
  VERSION 0.1.0
  LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS ON)

include_directories("Arduino_KNN/src")
add_executable(coba02 main.cpp "Arduino_KNN/src/KNNClassifier.cpp"
                      "Arduino_KNN/src/utility/KNNNode.cpp")
target_include_directories(coba02 PUBLIC "Arduino_KNN/src")
