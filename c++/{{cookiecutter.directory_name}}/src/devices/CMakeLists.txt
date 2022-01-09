# Internal library for devices

add_library(devices Devices.cpp)
target_include_directories(
  devices
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include/
)
target_compile_features(
  devices
  PUBLIC
  ${STANDARD_COMPILE_FEATURE}
)
