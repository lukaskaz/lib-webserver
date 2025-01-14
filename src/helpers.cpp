#include "webserver/helpers.hpp"

#include <arpa/inet.h>
#include <ifaddrs.h>

#include <cstring>

namespace http
{

std::string getIPAddress(const std::string& iface)
{
    std::string ip;
    struct ifaddrs* interfaces = NULL;

    if (getifaddrs(&interfaces) == 0)
    {
        struct ifaddrs* temp_addr = interfaces;
        while (temp_addr)
        {
            if (temp_addr->ifa_addr->sa_family == AF_INET)
            {
                if (strncmp(temp_addr->ifa_name, iface.c_str(), iface.size()) ==
                    0)
                {
                    ip = inet_ntoa(
                        ((struct sockaddr_in*)temp_addr->ifa_addr)->sin_addr);
                    break;
                }
            }
            temp_addr = temp_addr->ifa_next;
        }
    }
    freeifaddrs(interfaces);
    return ip;
}

} // namespace http
