enable_testing()

add_executable(
  device_test
  device_test.cpp)

target_compile_features(
  device_test
  PUBLIC
  ${STANDARD_COMPILE_FEATURE}
)

target_link_libraries(
  device_test
  PUBLIC
  gtest_main
  nlohmann_json::nlohmann_json
  fmt::fmt
  devices
)

include(GoogleTest)
gtest_discover_tests(device_test)
