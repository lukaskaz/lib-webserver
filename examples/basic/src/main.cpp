#include "webserver/server.hpp"

#include <iostream>

int main()
{
    try
    {
        uint16_t port{8010};
        http::Server server(port);
        server
            .get("/photos",
                 [](auto, auto res) {
                     res.headers.push_back("Connection: close");
                     res.headers.push_back("Max-Age: 0");
                     res.headers.push_back("Expires: 0");
                     res.headers.push_back("Cache-Control: no-cache, private");
                     res.headers.push_back("Pragma: no-cache");
                     res.headers.push_back(
                         "Content-Type: "
                         "multipart/x-mixed-replace;boundary=--boundary");

                     if (!res.send_header())
                     {
                         return;
                     }
                 })
            .get("/", [port](auto, auto res) {
                // redirect to main code under /img
                res >> "<html>"
                       "  <body>"
                       "    <h1>Camera streaming</h1>"
                       "    <img src='http://ip:port/img'/ width='640' "
                       "height='480'>"
                       "   </body>"
                       "</html>";
            });
        // comment out to avoid blocking test run of this example
        // server.listen();
    }
    catch (std::exception& err)
    {
        std::cerr << "[ERROR] " << err.what() << '\n';
    }

    return 0;
}
