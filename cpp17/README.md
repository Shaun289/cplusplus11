# 설계
- 각각의 프로젝트에서 run file과 library 를 만들도록함
- library 를 만들때 main.cpp 를 포함하지 않도록 함
- test 에서는 각각의 프로젝트명_test.cpp 파일에서 테스트 하도록 함

## Directory

+ CMakeLists.txt
+ README.md
+ span/
|  + span.cpp
|  + main.cpp
|  + CMakeLists.cpp
+ move
|  + move.cpp
|  + main.cpp
|  + CMakeLists.cpp
+ test
   + span.cpp
   + move.cpp
   + CMakeLists.cpp
   + build/
     + test (executable)

# Execute

```
$ make clean
$ make
$ ./build/span/span
```

# Reference
- [모두의 코드 씹어먹는 C++ - <19 - 2. C++ 프로젝트를 위한 CMake 사용법>](https://modoocode.com/332)
- [Automatically use the directory as the project name in CMake](https://stackoverflow.com/questions/12344368/automatically-use-the-directory-as-the-project-name-in-cmake)


