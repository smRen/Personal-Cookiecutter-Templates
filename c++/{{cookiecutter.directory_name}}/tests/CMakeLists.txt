enable_testing()

add_executable(
  hello_test
  hello_test.cpp)

target_compile_features(hello_test
  PUBLIC
  ${STANDARD_COMPILE_FEATURE}
)

target_link_libraries(
  hello_test
  PUBLIC
  gtest_main
  nlohmann_json::nlohmann_json
  fmt::fmt
  devices
)

include(GoogleTest)
gtest_discover_tests(hello_test)
