#include "socketClientLinux.h"
#include <sstream>
#include <signal.h>

constexpr int INIT_BUFFER = 0;
constexpr size_t SIZE_BUFFER = 255;

App::Socket::SocketClientLinux::SocketClientLinux(sockaddr_in __sockaddr_in):_socketClient(0),
            _sockaddr_in(__sockaddr_in){
    signal(SIGPIPE, SIG_IGN);
}

bool App::Socket::SocketClientLinux::open(){
    _socketClient = socket(AF_INET, SOCK_STREAM,0); //open socket
    if(_socketClient < 0)
        return false;

    if(connect(_socketClient,(struct sockaddr *)&_sockaddr_in,sizeof(_sockaddr_in)) < 0) //connect server
        return false;

    return true;
}

App::Socket::SocketClientLinux::~SocketClientLinux(){
    this->SocketClientLinux::close();
}

void App::Socket::SocketClientLinux::close(){
    ::close(_socketClient);
}

bool App::Socket::SocketClientLinux::send(const std::string & __sendStr) const {
    auto n = write(_socketClient,__sendStr.data(),__sendStr.size());
    if (n < 0)
        return false;
    return true;
}

std::string App::Socket::SocketClientLinux::read() {
    char buffer[SIZE_BUFFER+1]{INIT_BUFFER};//+1 end buffer
    auto n = ::read(_socketClient,buffer,SIZE_BUFFER);
    if (n < 1){
        return "";
    }
    std::stringstream s;
    s<<buffer;
    return s.str();
}
