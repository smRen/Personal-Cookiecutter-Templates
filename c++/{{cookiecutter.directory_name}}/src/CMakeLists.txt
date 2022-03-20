add_executable(
  main
  main.cpp
)

target_compile_features(
  main
  PUBLIC
  ${STANDARD_COMPILE_FEATURE}
)

target_link_libraries(
  main
  PUBLIC
  nlohmann_json::nlohmann_json
  fmt::fmt
  devices
)

set_target_properties(
  main
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
