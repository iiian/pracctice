cmake_minimum_required(VERSION 3.14)
project(praCCtice)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)

FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(
  praCCtice_tests 
  min_sum_path_test.cc min_sum_path.h min_sum_path.cc
  wildcard_matching_test.cc wildcard_matching.h wildcard_matching.cc
)
target_link_libraries(
  praCCtice_tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(praCCtice_tests)
