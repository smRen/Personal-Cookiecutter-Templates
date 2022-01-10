#include <gtest/gtest.h>
#include <smren/devices/Devices.hpp>

using namespace smren;

class DeviceTest : public ::testing::Test {
protected:
    Device<Camera> camera_default{};
    Device<Camera> camera_named1{"Red camera", 1};
    Device<Camera> camera_named2{"Green camera", 2};
    Device<Filter> filter_default{};
    Device<Filter> filter_named1{"Red filter", 1};
    Device<Filter> filter_named2{"Green filter", 2};
};

TEST_F(DeviceTest, TestNamedCamera) {
    EXPECT_STREQ(camera_named1.m_name.c_str(), "Red camera");
    EXPECT_STREQ(camera_named2.m_name.c_str(), "Green camera");
    camera_named1.print_device_properties();
}

TEST_F(DeviceTest, TestDefaultCamera) {
    EXPECT_STREQ(camera_default.m_name.c_str(), "Default name");
}

TEST_F(DeviceTest, TestNamedFilter) {
    EXPECT_STREQ(filter_named1.m_name.c_str(), "Red filter");
    EXPECT_STREQ(filter_named2.m_name.c_str(), "Green filter");
    filter_named1.print_device_properties();
}

TEST_F(DeviceTest, TestDefaultFilter) {
    EXPECT_STREQ(filter_default.m_name.c_str(), "Default name");
}
