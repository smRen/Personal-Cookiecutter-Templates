cmake_minimum_required(VERSION 3.20)

project(
  {{cookiecutter.cmake_project_name}}
  VERSION {{cookiecutter.cmake_version}}
  DESCRIPTION "{{cookiecutter.cmake_description}}"
  LANGUAGES CXX)

# Testing
include(FetchContent)
FetchContent_Declare(
  googletest
  # Check URL and update link regularly!
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Formatting library
FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 8.1.0)
FetchContent_MakeAvailable(fmtlib)

# Json library
FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
  GIT_TAG v3.10.4)
FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# Main source code directory
add_subdirectory(src)

# Testing directory
add_subdirectory(tests)
