#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <string_view>
#include <vector>
#include <array>
#include <span>
#include <fstream>

// Third party libs
#include <nlohmann/json.hpp>
#include <fmt/core.h>

// User libs
#include <smren/devices/Devices.hpp>

using json = nlohmann::json;
namespace fs = std::filesystem;

void printMe(std::span<int> container) {
    std::cout << "container.size(): " << container.size() << '\n';  // (4)
    for(auto e : container) std::cout << e << ' ';
    std::cout << "\n\n";
}

void read_config_file(json& j_config, std::string_view filename) {
    fs::path json_file{filename};
    if (fs::exists(json_file)) {
        j_config = json::parse(std::ifstream(json_file));
        std::cout << std::setw(4) << j_config << '\n';
    } else {
        throw std::runtime_error(fmt::format("{} not found", filename));
    }
}

int main() {

    // C++20 checks
    int arr[]{1, 2, 3, 4, 5};
    printMe(arr);
    std::vector vec{1, 2, 3, 4, 5};
    printMe(vec);
    std::array arr2{4, 5, 6};
    printMe(arr2);

    // Format check
    std::cout << fmt::format("Testing {1} {0}\n\n", "zero", "one");

    // Json check
    try {
        json j_config;
        read_config_file(j_config, "config.json");
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    // Check user libs (Device)
    smren::Camera pi_camera{};
    pi_camera.print_info();
    std::cout << "Name: " << pi_camera.name << '\n';

    smren::Filter filter{1, "Green Filter"};
    filter.print_info();
    std::cout << "Name: " << filter.name << '\n';
    return EXIT_SUCCESS;
}
