#include <smren/devices/Devices.hpp>

using namespace smren;

Camera::Camera(int index) {
    std::cout << "Camera " << index << " initialized.\n";
}

Filter::Filter(int index) {
    std::cout << "Filter " << index << " initialized.\n";
}
