cmake_minimum_required(VERSION 3.0.0)
project(
  coba02
  VERSION 0.1.0
  LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS ON)

include_directories("Arduino_KNN/src")
add_library(ardunio_knn SHARED "Arduino_KNN/src/KNNClassifier.cpp"
                               "Arduino_KNN/src/utility/KNNNode.cpp")
target_include_directories(ardunio_knn PUBLIC "Arduino_KNN/src")

add_executable(color color.cpp)
target_link_libraries(color ardunio_knn)

add_executable(or_gate or_gate.cpp)
target_link_libraries(or_gate ardunio_knn)

add_executable(and_gate and_gate.cpp)
target_link_libraries(and_gate ardunio_knn)

add_executable(xor_gate xor_gate.cpp)
target_link_libraries(xor_gate ardunio_knn)

add_executable(near near.cpp)
target_link_libraries(near ardunio_knn)
