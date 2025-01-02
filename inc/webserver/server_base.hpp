#pragma once

#include "webserver/req_res.hpp"
#include "webserver/support.hpp"
#include "webserver/thread_pool.hpp"

#include <unistd.h>

#include <functional>
#include <map>

class Server_base
{
  public:
    using Functions =
        std::map<std::string, std::function<void(Request&, Response&)>>;

    Server_base(uint16_t port)
    {
        server_impl::init_server(sock_fd, s_addr, port);
    }

    ~Server_base()
    {
        close(sock_fd);
    }

  protected:
    Thread_pool tp;
    Functions paths_f;

    int sock_fd;
    sockaddr_in s_addr;
};
