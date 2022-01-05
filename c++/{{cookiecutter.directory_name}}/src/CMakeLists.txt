set(STANDARD_C++ "{{cookiecutter.cpp_standard}}")

if (STANDARD_C++ STREQUAL "C++20")
  set(STANDARD_COMPILE_FEATURE cxx_std_20)
elseif (STANDARD_C++ STREQUAL "C++17")
  set(STANDARD_COMPILE_FEATURE cxx_std_17)
elseif (STANDARD_C++ STREQUAL "C++11")
  set(STANDARD_COMPILE_FEATURE cxx_std_11)
endif()

add_executable(main main.cpp)
target_compile_features(main PRIVATE ${STANDARD_COMPILE_FEATURE})
target_include_directories(main PUBLIC ../include)
