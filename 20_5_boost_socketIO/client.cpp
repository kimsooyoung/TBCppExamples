#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
        {
            std::cerr << "Usage : client <host>" << std::endl;
            return 1;
        }

        tcp::iostream stream(argv[1], std::to_string(int(13))); // port number 13
        if (!stream)
        {
            std::cout << "Unable to connect : " << stream.error().message() << std::endl;
            return 1;
        }

        stream << "Hello From Client";
        stream << std::endl;

        // recv msg from srv
        std::string recv_msg;
        std::getline(stream, recv_msg);
        std::cout << recv_msg << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}