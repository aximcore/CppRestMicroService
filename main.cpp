#include "controller/EchoController.hpp"
#include "signal/SignalHandler.hpp"

#include <iostream>

int main() {
    EchoController echo;
    echo.setEndPoint("http://localhost:5678/asd");
    try {
        echo.open().wait();
        SignalHandler::waitForUserInterrupt();
        echo.close().wait();
    } catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
}
