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

// Continue writing tests for other functionalities...

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
