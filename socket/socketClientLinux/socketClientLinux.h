#pragma once
#include "interface/iSocket/iSocketClient/iSocketClient.h"
#include <netinet/in.h>

namespace App{
    namespace Socket{
        struct SocketClientLinux: public App::Interface::ISocketClient {
            SocketClientLinux(sockaddr_in __sockaddr_in);
            ~SocketClientLinux();
            bool open() override;
            void close() override;
            bool send(const std::string & __sendStr) const override;
            std::string read() override;
        private:
            int _socketClient;
            sockaddr_in _sockaddr_in;
        };
    }
}


