#pragma once
#include "interface/iFactory/iFSocketClient/iFSocketClient.h"
#include "interface/iFactory/iFSockaddr_in/iFSockaddr_in.h"
#include "socket/socketClientLinux/socketClientLinux.h"

namespace App{
    namespace Factory{
        struct FSocketClientLinux : public Interface::IFSocketClient{
            FSocketClientLinux(Interface::IFSockaddr_in * __fSockaddr_in);
            Socket::SocketClientLinux * createISocketClient() const override;
        private:
            Interface::IFSockaddr_in * _fSockaddr_in;
        };
    }
}
