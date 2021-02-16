#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(){

    try
    {
        boost::asio::io_service io_service;

        // make endpoint with tcp version4 
        // this endpoint will use port number 13
        tcp::endpoint endpoint(tcp::v4(), 13);
        tcp::acceptor acceptor(io_service, endpoint);

        std::cout << "Server Started" << std::endl;

        for(;;){
            std::string message_to_send = "Hello From Server";

            boost::asio::ip::tcp::iostream stream;
            std::cout << "check 1" << std::endl;

            boost::system::error_code ec;
            acceptor.accept(*stream.rdbuf(), ec);

            std::cout << "check 2" << std::endl;

            if(!ec){
                for(;;){
                    std::string line;
                    std::getline(stream, line);
                    if(line != "")                    
                        std::cout << line << std::endl;

                    std::cout << ">> ";
                    getline(std::cin, line);

                    stream << message_to_send;
                    stream << std::endl;
                }
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}