cmake_minimum_required(VERSION 3.11)
PROJECT(cplusplus11)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# googletest 빌드
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main  # Use the main branch to get the latest version
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(cpp11/functional)
