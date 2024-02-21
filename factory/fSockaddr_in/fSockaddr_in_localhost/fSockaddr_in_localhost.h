#pragma once
#include "interface/iFactory/iFSockaddr_in/iFSockaddr_in.h"

namespace App{
    namespace Factory{
    struct FSockaddr_in_localhost: public App::Interface::IFSockaddr_in {
            FSockaddr_in_localhost(int __port);
            ~FSockaddr_in_localhost() = default;
            sockaddr_in getSockaddr_in() override;
        private:
            int _port;
        };
    }
}


