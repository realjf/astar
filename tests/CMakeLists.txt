cmake_minimum_required(VERSION 3.12)

set(ASTAR_VERSION 1.0)
set(PROJECT_NAME astar)
project(${PROJECT_NAME} VERSION ${ASTAR_VERSION} LANGUAGES C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unknown-pragmas -Wno-format -O3")

# set executable output path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/../bin_test)

# set library output path
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/../lib)

set(ASTAR_SRS ../src/astar.cpp ../src/node.cpp ../src/map.cpp)
set(ASTAR_HEADERS ../src/astar.h ../src/node.h ../src/map.h)

add_executable(${PROJECT_NAME} main.cpp ${ASTAR_SRS} ${ASTAR_HEADERS})
