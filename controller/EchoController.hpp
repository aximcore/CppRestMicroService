#pragma once

#include "BaseController.hpp"

class EchoController : public BaseController {
public:
    EchoController() : BaseController() {
    }

    ~EchoController() {}

    void initHandlers() override {
        listener.support(methods::GET, std::bind(&EchoController::handleGet, this, std::placeholders::_1));
        listener.support(methods::POST, std::bind(&EchoController::handlePost, this, std::placeholders::_1));
    }

    void handleGet(http_request message) override {
        auto response = json::value::object();
        response["example"] = json::value::string("value");
        message.reply(status_codes::OK, response);
    }

    void handlePost(http_request message) override {
        message.reply(status_codes::OK, message.body()); // echo
    }

};
