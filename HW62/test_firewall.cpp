#include <gtest/gtest.h>
#include "ip.h"
#include "port.h"
#include "string.h"
#include "string-array.h"


TEST(StringTest, TrimFunction) {
    String str    ("hello world");
    ASSERT_EQ(str.trim().as_string(), "hello world");
}

TEST(IpTest, MatchFunction) {
    Ip ipRule(String("src-ip=192.168.1.1/24"));
    String packet ("src-ip=192.168.1.100,dst-ip=10.0.0.1");
    ASSERT_TRUE(ipRule.match(packet));
}

TEST(PortTest, MatchFunction) {
    Port portRule(String("src-port=8080-8080"));
    String packet ( "src-ip=192.168.1.100,src-port=8080,dst-ip=10.0.0.1");
    ASSERT_TRUE(portRule.match(packet));
}
TEST(StringTest, SplitFunction) {
    String str = "192.168.1.1";
    auto parts = str.split(".");
    ASSERT_EQ(parts.size(), 4);
    EXPECT_EQ(parts.get(0)->as_string(), "192");
    EXPECT_EQ(parts.get(1)->as_string(), "168");
    EXPECT_EQ(parts.get(2)->as_string(), "1");
    EXPECT_EQ(parts.get(3)->as_string(), "1");
}
TEST(StringTest, ToIntegerFunction) {
    String str = "8080";
    int value = str.to_integer();
    ASSERT_EQ(value, 8080);
}
TEST(IpTest, SetValueAndMatchFunction) {
    String rule = "192.168.0.0/16";
    Ip ipRule(rule);
    String packetGood = "src-ip=192.168.1.100";
    String packetBad = "src-ip=10.0.0.1";
    ASSERT_TRUE(ipRule.match(packetGood));
    ASSERT_FALSE(ipRule.match(packetBad));
}
TEST(PortTest, SetValueAndMatchFunction) {
    String rule = "1000-2000";
    Port portRule(rule);
    String packetInsideRange = "src-port=1500";
    String packetOutsideRange = "src-port=2500";
    ASSERT_TRUE(portRule.match(packetInsideRange));
    ASSERT_FALSE(portRule.match(packetOutsideRange));
}
TEST(StringArrayTest, AddRemoveGetFunctions) {
    StringArray arr;
    String str1 = "test1";
    String str2 = "test2";
    arr.add(&str1);
    arr.add(&str2);

    // Test adding and getting elements
    ASSERT_EQ(arr.size(), 2);
    EXPECT_EQ(arr.get(0)->as_string(), "test1");
    EXPECT_EQ(arr.get(1)->as_string(), "test2");

    // Test removing an element
    arr.remove(0);
    ASSERT_EQ(arr.size(), 1);
    EXPECT_EQ(arr.get(0)->as_string(), "test2");
}



// Continue writing tests for other functionalities...

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
