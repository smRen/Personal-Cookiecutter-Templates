set(STANDARD_C++ {{cookiecutter.cpp_standard}})

if (STANDARD_C++ STREQUAL "C++20")
  set(STANDARD_COMPILE_FEATURE cxx_std_20)
elseif (STANDARD_C++ STREQUAL "C++17")
  set(STANDARD_COMPILE_FEATURE cxx_std_17)
elseif (STANDARD_C++ STREQUAL "C++11")
  set(STANDARD_COMPILE_FEATURE cxx_std_11)
endif()

add_executable(main main.cpp)
target_compile_features(main PRIVATE ${STANDARD_COMPILE_FEATURE})
target_include_directories(
  main
  PRIVATE
  {{ "${{{0}_SOURCE_DIR}}/include".format(cookiecutter.cmake_project_name) }})
target_link_libraries(
  main
  PRIVATE
  nlohmann_json::nlohmann_json
  fmt::fmt)
