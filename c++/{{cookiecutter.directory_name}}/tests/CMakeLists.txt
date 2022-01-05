enable_testing()

add_executable(
  hello_test
  hello_test.cpp)

target_compile_features(hello_test
  PRIVATE
  cxx_std_20)

target_link_libraries(
  hello_test
  PRIVATE
  gtest_main
  nlohmann_json::nlohmann_json
  fmt::fmt)

include(GoogleTest)
gtest_discover_tests(hello_test)
