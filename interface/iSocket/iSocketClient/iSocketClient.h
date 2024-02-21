#pragma once
#include <string>

namespace App{
    namespace Interface{
        struct ISocketClient {
            virtual bool open() = 0;
            virtual void close() = 0;
            virtual bool send(const std::string &) const = 0;
            virtual std::string read() = 0;
            virtual ~ISocketClient() = default;
        };
    }
}

 
