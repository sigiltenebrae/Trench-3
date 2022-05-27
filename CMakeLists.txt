cmake_minimum_required(VERSION 3.22)
project(Trench_3)

set(CMAKE_CXX_STANDARD 23)

add_executable(Trench_3 main.cpp)

set(OpenCV_DIR "C:\\opencv\\mingw-build")

find_package( OpenCV REQUIRED )

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )