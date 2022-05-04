# CMakeList.txt : CMake project for daedalus-linux, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)
project ("daedalus-bot")

add_subdirectory(binapi)

file(GLOB DAEDALUS_SRC
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/strategies/*.cpp"
        )
include_directories(
        ${PROJECT_SOURCE_DIR}/include
)
add_executable (daedalus-bot "main.cpp" ${DAEDALUS_SRC})
target_link_libraries(daedalus-bot PUBLIC binapi)


# Add Tests
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(daedalus-test "test/test.cpp" ${DAEDALUS_SRC})
target_link_libraries(daedalus-test ${GTEST_LIBRARIES} pthread)