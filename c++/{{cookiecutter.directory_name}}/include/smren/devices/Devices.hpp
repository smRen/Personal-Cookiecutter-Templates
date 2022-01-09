#pragma once
#include <iostream>
#include <string>
#include <string_view>

namespace smren {

class BaseDevice {
  public:
    const std::string name;

  protected:
    const int m_device_index;
    const int m_device_handle;

    explicit BaseDevice(int device_index, std::string_view device_name);
    virtual ~BaseDevice() = default;

    virtual void print_info() = 0;
};

class Camera : public BaseDevice {
  public:
    /// @brief Choose specific camera.
    explicit Camera(int index = 0,
                    std::string_view device_name = "Default Camera");

    /// @brief Print current device information
    void print_info() override;
};

class Filter : public BaseDevice {
  public:
    /// @brief Choose specific filter.
    explicit Filter(int index = 0,
                    std::string_view device_name = "Default Filter");

    /// @brief Print current device information
    void print_info() override;
};
} // namespace smren
