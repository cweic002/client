#include "fSockaddr_in_localhost.h"
#include <netdb.h>
#include <string.h>

constexpr int INT_NULL = 0;

App::Factory::FSockaddr_in_localhost::FSockaddr_in_localhost(int __port):_port(__port){}

sockaddr_in App::Factory::FSockaddr_in_localhost::getSockaddr_in(){
    sockaddr_in serv_addr;
    auto server = gethostbyname("localhost");
    memset(&serv_addr,INT_NULL,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr,server->h_addr,server->h_length);
    serv_addr.sin_port = htons(_port);
    return serv_addr;
}
