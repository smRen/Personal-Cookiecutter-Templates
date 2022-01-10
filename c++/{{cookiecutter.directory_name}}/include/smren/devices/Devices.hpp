#pragma once
#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

namespace smren {

class Camera {
public:
    /// @brief Initialize camera based on index
    explicit Camera(int index);
};

class Filter {
public:
    /// @brief Initialize filter based on index
    explicit Filter(int index);
};

template <typename T>
class Device {
    static_assert(std::is_base_of<Filter, T>::value || std::is_base_of<Camera, T>::value, "Type T must be a Camera or Filter");
    const int m_device_index;
    const int m_device_handle;
    T m_device;

public:
    const std::string m_name;
    Device(std::string_view name = "Default name", int index = 0)
        : m_device_index{index},
          m_device_handle{0},
          m_device{index},
          m_name{name} {}

    void print_device_properties();
};

template <typename T>
void Device<T>::print_device_properties() {
    std::cout << "Index: " << m_device_index << '\n'
                << "Handle: " << m_device_handle << '\n'
                << "Name: " << m_name << '\n';
}

}  // namespace smren
