include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../)

enable_testing()

add_executable(
    basic_test
    basic_test.cc
    vec_test.cc
)

target_link_libraries(
  basic_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(basic_test)