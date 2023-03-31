
cmake_minimum_required(VERSION 3.12)

set(ASTAR_VERSION 1.0)
set(PROJECT_NAME astar)
project(${PROJECT_NAME} VERSION ${ASTAR_VERSION} LANGUAGES C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unknown-pragmas -Wno-format -O3")

set(ASTAR_SRS src/astar.cpp src/node.cpp src/map.cpp)
set(ASTAR_HEADERS src/astar.h src/node.h src/map.h)

# set library output path
# set(LIBRARY_OUTPUT_DIRECTORY lib)
# set(LIBRARY_OUTPUT_PATH lib)
add_library(${PROJECT_NAME} SHARED ${ASTAR_SRS} ${ASTAR_HEADERS})
add_library(${PROJECT_NAME}static STATIC ${ASTAR_SRS} ${ASTAR_HEADERS})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

if(UNIX)
    # On unix-like platforms the library is almost always called libastar
    set_target_properties(${PROJECT_NAME} ${PROJECT_NAME}static PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
elseif(BUILD_SHARED_LIBS AND WIN32)
    # Creates astar.dll when building shared library version
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".dll")
endif()
