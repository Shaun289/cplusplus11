cmake_minimum_required(VERSION 3.11)
SET(CMAKE_CXX_STANDARD 20)

SET(PROJECT_NAME "cpp11_study")

project(
  ${PROJECT_NAME}
  VERSION 0.1
  DESCRIPTION "cpp11 study project"
  LANGUAGES CXX)

add_subdirectory(vector)

