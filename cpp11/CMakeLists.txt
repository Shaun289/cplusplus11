cmake_minimum_required(VERSION 3.11)
SET(CMAKE_CXX_STANDARD 20)

SET(PROJECT_NAME "cpp11_study")

project(
  ${PROJECT_NAME}
  VERSION 0.1
  DESCRIPTION "cpp11 study project"
  LANGUAGES CXX)

# g++ 9.4 does not support span
#add_subdirectory(span)
add_subdirectory(decltype)
add_subdirectory(initializer_list)
add_subdirectory(bitset)
add_subdirectory(constexpr)
add_subdirectory(lambda_function)
add_subdirectory(optional)

