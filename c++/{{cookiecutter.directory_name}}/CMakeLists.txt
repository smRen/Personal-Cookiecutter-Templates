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
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Main source code directory
add_subdirectory(src)

# Testing directory
add_subdirectory(tests)
