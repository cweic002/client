#include "fSocketClientLinux.h"

App::Factory::FSocketClientLinux::FSocketClientLinux(Interface::IFSockaddr_in * __fSockaddr_in)
                :_fSockaddr_in(__fSockaddr_in){}

App::Socket::SocketClientLinux * App::Factory::FSocketClientLinux::createISocketClient() const {
    return new Socket::SocketClientLinux(_fSockaddr_in->getSockaddr_in());
}
