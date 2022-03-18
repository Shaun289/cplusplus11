CMAKE_MINIMUM_REQUIRED(VERSION 3.15.0)

SET(proj_name "AudioMux")
PROJECT( ${proj_name} )

SET(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)
add_subdirectory(test)


