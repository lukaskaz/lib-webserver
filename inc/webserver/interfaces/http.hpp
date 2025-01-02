#pragma once

#include "webserver/req_res.hpp"
#include "webserver/server_base.hpp"
#include "webserver/support.hpp"

namespace http
{

class Server : public Server_base
{
  public:
    using Callback = std::function<void(Request&, Response&)>;

    Server(uint16_t);
    ~Server();

    void listen();
    Server& get(const std::string&, Callback&&);
};

}; // namespace http
