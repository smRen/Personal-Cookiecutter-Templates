#include <gtest/gtest.h>
#include <smren/devices/Devices.hpp>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

TEST(DeviceTest, TestMembers) {
    smren::Camera pi_camera{};
    
    EXPECT_STREQ(pi_camera.name.c_str(), "Default Camera");
    EXPECT_STRNE(pi_camera.name.c_str(), "Bob");
}
