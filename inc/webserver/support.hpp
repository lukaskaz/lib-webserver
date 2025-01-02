#pragma once

#include <arpa/inet.h>
#include <sys/socket.h>

#include <atomic>
#include <cstring>
#include <map>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>

namespace server_impl
{

using Headers = std::vector<std::string>;
using Params = std::map<std::string, std::string>;

void parse(std::string, Headers&, Params&);
int accept(int);
std::string receive(int);
bool send_h(int, const std::vector<std::string>&);
bool send_m(int, const std::string&);
std::string get_request_path(const std::string&);
void init_server(int&, sockaddr_in&, uint16_t);

}; // namespace server_impl
