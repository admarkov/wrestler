#include <boost/beast.hpp>
#include <boost/asio.hpp>

namespace wrestler {

    using boost::string_view;
    using std::string;
    namespace net = boost::asio;

    class WrestlerConfig {
    public:
        WrestlerConfig(string_view host)
            : threads_(1)
        {
            // TODO: URL parser
            auto protocolDelimeter = host.find("://");
            // TODO: handling protocol
            if (protocolDelimeter != string_view::npos) {
                host = host.substr(protocolDelimeter + 3);
            }
            auto portDelimeter = host.rfind(':');
            if (portDelimeter == string_view::npos) {
                port_ = 80;
            } else {
                string port = "";
                auto ptr = portDelimeter;
                while (++ptr < host.length() && isdigit(host[ptr])) {
                    port.push_back(host[ptr]);
                }
                port_ = stoi(port);
            }
            host = host.substr(0, portDelimeter);
            address_ = net::ip::make_address(host.to_string());
        }

        ~WrestlerConfig() = default;

        net::ip::address address() {
            return address_;
        }

        uint8_t port() {
            return port_;
        }

        uint8_t threads() {
            return threads_;
        }

        WrestlerConfig& setThreads(uint8_t t) {
            threads_ = t;
            return *this;
        }

    private:
        net::ip::address    address_;
        uint8_t             port_;
        uint8_t             threads_;
    };

}