#pragma once

#include <condition_variable>
#include <mutex>
#include <iostream>
#include <signal.h>

static std::condition_variable SignalCondition;
static std::mutex SignalMutex;

class SignalHandler {
public:
    static void hookSIGINT() {
        signal(SIGINT, handleUserInterrupt);
    }

    static void handleUserInterrupt(int signal){
        if (signal == SIGINT) {
            std::cout << "SIGINT" << std::endl;
            SignalCondition.notify_one();
        }
    }

    static void waitForUserInterrupt() {
        std::unique_lock<std::mutex> lock { SignalMutex };
        SignalCondition.wait(lock);
        std::cout << "interrup program..." << std::endl;
        lock.unlock();
    }
};
