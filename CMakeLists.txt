cmake_minimum_required(VERSION 3.10)
project(vienna_audio_engine)

set(EXECUTABLE_NAME AudioFileConverter)
set(TEST_EXECUTABLE_NAME AFC_test)

set(CMAKE_CXX_STANDARD 17)

# add googletest as a dependency
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(PUBLIC_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/include/)
FILE(GLOB HEADER_FILES
        ${CMAKE_SOURCE_DIR}/include/*.h)
FILE(GLOB SOURCE_FILES
        ${CMAKE_SOURCE_DIR}/src/*.cpp)
FILE(GLOB TEST_FILES
        ${CMAKE_SOURCE_DIR}/tests/*.cpp)

add_executable(${EXECUTABLE_NAME} ${HEADER_FILES} ${SOURCE_FILES})
add_library(${EXECUTABLE_NAME}_lib STATIC ${HEADER_FILES} ${SOURCE_FILES})

add_executable(${TEST_EXECUTABLE_NAME} ${TEST_FILES})
include_directories(${TEST_EXECUTABLE_NAME} ${PUBLIC_INCLUDE_DIRS})
add_test(NAME ${TEST_EXECUTABLE_NAME} COMMAND ${TEST_EXECUTABLE_NAME})
target_link_libraries(${TEST_EXECUTABLE_NAME} ${EXECUTABLE_NAME}_lib gtest_main)

include(GoogleTest)
gtest_discover_tests(${TEST_EXECUTABLE_NAME})
