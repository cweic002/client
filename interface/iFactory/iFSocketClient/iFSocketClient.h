#pragma once
#include "interface/iSocket/iSocketClient/iSocketClient.h"

namespace App {
    namespace Interface {
        struct IFSocketClient {
            virtual Interface::ISocketClient * createISocketClient() const = 0;
            virtual ~IFSocketClient() = default;
        };
    }
}
