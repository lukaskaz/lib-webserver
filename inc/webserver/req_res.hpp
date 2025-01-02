#pragma once

#include "webserver/support.hpp"

#include <string>
#include <vector>

struct Request
{
    server_impl::Headers headers;
    server_impl::Params query;
    std::string path;

    Request(const std::string& p) : path(p)
    {}
};

struct Response
{
    int client;
    server_impl::Headers headers;

    Response(int clt) : client(clt), headers{"HTTP/1.1 200 OK"}
    {}

    bool write(const std::string& msg) const
    {
        return server_impl::send_h(client, headers) &&
               server_impl::send_m(client, msg);
    }

    bool send_header() const
    {
        return server_impl::send_h(client, headers);
    }

    bool send_msg(const std::string& msg) const
    {
        return server_impl::send_m(client, msg);
    }
};

void operator>>(const Response&, const std::string&);
