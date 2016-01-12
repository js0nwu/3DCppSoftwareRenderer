cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
file(GLOB thirdpillow_SRC
    "src/*.cpp"
)
add_executable(thirdpillow ${thirdpillow_SRC} src/displayer.cpp src/displayer.h src/inputter.cpp src/inputter.h src/inputtable.h src/timekeeper.cpp src/timekeeper.h)
target_link_libraries(thirdpillow ${SDL2_LIBRARY})
file(COPY res DESTINATION .)
