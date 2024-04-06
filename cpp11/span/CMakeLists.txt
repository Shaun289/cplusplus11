SET(PROJECT_NAME "span")
SET(CMAKE_CXX_STANDARD 20)

project(
  ${PROJECT_NAME}
  VERSION 0.1
  DESCRIPTION "std::span study"
  LANGUAGES CXX)

add_executable (${PROJECT_NAME} main.cpp)

