#include <ostream>
#include <iostream>
#include <chrono>
#include <sstream>
#include <thread>
#include <iomanip>
#include <memory>
#include "factory/fSocketClientLinux/fSocketClientLinux.h"
#include "factory/fSockaddr_in/fSockaddr_in_localhost/fSockaddr_in_localhost.h"

using namespace std::chrono_literals;

int main(int argc, char *argv[])
{
    if (argc < 4)
        return (std::cout<<"usage name port time"<<std::endl,0);
    int portno = atoi(argv[2]);
    int timer = atoi(argv[3]);
    if(timer<1)
        return (std::cout<<"Error: invalid timer"<<std::endl,0);
    auto fSockLocalhost = App::Factory::FSockaddr_in_localhost(portno);
    auto fSocket = App::Factory::FSocketClientLinux(&fSockLocalhost);
    auto client_server = std::shared_ptr<App::Interface::ISocketClient>(fSocket.createISocketClient());
    if(!client_server->open())
        return (std::cout<<"Error: connect server"<<std::endl,0);
    int size = 100;
    for(int i=0; i<size; ++i){
        auto now = std::chrono::system_clock::now();
        std::time_t t_c = std::chrono::system_clock::to_time_t(now);
        auto ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch()%1000;
        std::tm* timeinfo;
        char buffer [21]{0};
        timeinfo = std::localtime(&t_c);
        std::strftime(buffer,20,"%F %T",timeinfo);
        std::stringstream s;
        s<<"["<<buffer<<":"<<std::setfill('0')<<std::setw(3)<<ms.count()<<"] "<<argv[1]<<std::endl;
        auto str = s.str();
        std::cout<<str;
        if(!client_server->send(str)){
            return (std::cout<<"Error: send message to server"<<std::endl,0);
        }
        std::this_thread::sleep_for(1s * timer);
    }
    client_server->close();
    return 0;
}
