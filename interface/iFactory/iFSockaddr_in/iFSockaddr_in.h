#pragma once

#include <netinet/in.h>

namespace App{
    namespace Interface{
        struct IFSockaddr_in {
            virtual ~IFSockaddr_in()=default;
            virtual sockaddr_in getSockaddr_in() = 0;
        };
    }
}


