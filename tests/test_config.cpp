#include "gtest/gtest.h"
#include "../lib/params.h"

TEST(TestServerParams, Threads) {
    wrestler::ServerParams params("239.239.17.17");
    EXPECT_EQ(params.threads(), 1);
    params.setThreads(2);
    EXPECT_EQ(params.threads(), 2);
    auto params2 = wrestler::ServerParams("17.17.239.239").setThreads(8);
    EXPECT_EQ(params2.threads(), 8);
}

TEST(TestServerParams, JustIpV2) {
    wrestler::ServerParams params("239.239.17.17");
    EXPECT_EQ(params.port(), 80);
    EXPECT_EQ(params.address(), boost::asio::ip::make_address_v4("239.239.17.17"));
}

TEST(TestServerParams, InvalidIpV4) {
    EXPECT_ANY_THROW(
        wrestler::ServerParams params("339.239.17.17");
    );
}

TEST(TestServerParams, IpWithProtocol) {
    wrestler::ServerParams params("http://239.239.17.17");
    EXPECT_EQ(params.port(), 80);
    EXPECT_EQ(params.address(), boost::asio::ip::make_address_v4("239.239.17.17"));
}

TEST(TestServerParams, IpWithPort) {
    wrestler::ServerParams params("239.239.17.17:220");
    EXPECT_EQ(params.port(), 220);
    EXPECT_EQ(params.address(), boost::asio::ip::make_address_v4("239.239.17.17"));
}

TEST(TestServerParams, IpWithProtocolAndPort) {
    wrestler::ServerParams params("https://239.239.17.17:220");
    EXPECT_EQ(params.port(), 220);
    EXPECT_EQ(params.address(), boost::asio::ip::make_address_v4("239.239.17.17"));
}
