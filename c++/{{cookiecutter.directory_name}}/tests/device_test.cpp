#include <gtest/gtest.h>
#include <smren/devices/Devices.hpp>

using namespace smren;

class DeviceTest : public ::testing::Test {
protected:
    void SetUp() override {
    }
    Camera camera_default{};
    Camera camera_named{0, "Red Camera"};
    Filter filter_default{};
    Filter filter_named{1, "Green Filter"};
};


TEST_F(DeviceTest, TestNamedCamera) {
    EXPECT_STREQ(camera_named.name.c_str(), "Red Camera");
}

TEST_F(DeviceTest, TestDefaultCamera) {
    EXPECT_STREQ(camera_default.name.c_str(), "Default Camera");
}

TEST_F(DeviceTest, TestNamedFilter) {
    EXPECT_STREQ(filter_named.name.c_str(), "Green Filter");
}

TEST_F(DeviceTest, TestDefaultFilter) {
    EXPECT_STREQ(filter_default.name.c_str(), "Default Filter");
    EXPECT_STRNE(filter_default.name.c_str(), "Bob");
}
