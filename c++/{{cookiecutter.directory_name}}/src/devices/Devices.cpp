#include <smren/devices/Devices.hpp>

using namespace smren;

// Implementation of BaseDevice
BaseDevice::BaseDevice(int device_index, std::string_view device_name)
    : name{device_name},
      m_device_index{device_index},
      m_device_handle{0}
{}

// Implementation of Camera
Camera::Camera(int index, std::string_view device_name)
    : BaseDevice{index, device_name}
{}

void Camera::print_info() {
    std::cout << "Current device index: " << m_device_index << '\n'
              << "Current device handle: " << m_device_handle << '\n'
              << "Current device name: " << name << '\n';
}

// Implementation of Filter
Filter::Filter(int index, std::string_view device_name)
    : BaseDevice{index, device_name}
{}

void Filter::print_info() {
    std::cout << "Current device index: " << m_device_index << '\n'
              << "Current device handle: " << m_device_handle << '\n'
              << "Current device name: " << name << '\n';
}
