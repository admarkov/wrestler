#include "gtest/gtest.h"
#include "../lib/config.h"

TEST(TestWrestlerConfig, Threads) {
    wrestler::WrestlerConfig config("239.239.17.17");
    EXPECT_EQ(config.threads(), 1);
    config.setThreads(2);
    EXPECT_EQ(config.threads(), 2);
    auto config2 = wrestler::WrestlerConfig("17.17.239.239").setThreads(8);
    EXPECT_EQ(config2.threads(), 8);
}

TEST(TestWrestlerConfig, JustIpV2) {
    wrestler::WrestlerConfig config("239.239.17.17");
    EXPECT_EQ(config.port(), 80);
    EXPECT_EQ(config.address(), boost::asio::ip::make_address_v4("239.239.17.17"));
}

TEST(TestWrestlerConfig, InvalidIpV4) {
    EXPECT_ANY_THROW(
        wrestler::WrestlerConfig config("339.239.17.17");
    );
}

TEST(TestWrestlerConfig, IpWithProtocol) {
    wrestler::WrestlerConfig config("http://239.239.17.17");
    EXPECT_EQ(config.port(), 80);
    EXPECT_EQ(config.address(), boost::asio::ip::make_address_v4("239.239.17.17"));
}

TEST(TestWrestlerConfig, IpWithPort) {
    wrestler::WrestlerConfig config("239.239.17.17:220");
    EXPECT_EQ(config.port(), 220);
    EXPECT_EQ(config.address(), boost::asio::ip::make_address_v4("239.239.17.17"));
}

TEST(TestWrestlerConfig, IpWithProtocolAndPort) {
    wrestler::WrestlerConfig config("https://239.239.17.17:220");
    EXPECT_EQ(config.port(), 220);
    EXPECT_EQ(config.address(), boost::asio::ip::make_address_v4("239.239.17.17"));
}
