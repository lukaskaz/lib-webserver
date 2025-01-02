#include "webserver/req_res.hpp"

void operator>>(const Response& res, const std::string& msg)
{
    res.write(msg);
}
