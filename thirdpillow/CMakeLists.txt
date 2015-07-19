cmake_minimum_required(VERSION 2.8)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )
file(GLOB thirdpillow_SRC
    "src/*.cpp"
)
add_executable(thirdpillow ${thirdpillow_SRC})
target_link_libraries(thirdpillow ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
