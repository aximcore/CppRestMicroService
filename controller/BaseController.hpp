#pragma once

#include <cpprest/http_listener.h>
#include <cpprest/http_msg.h>

using namespace web;
using namespace http;
using namespace http::experimental::listener;

class BaseController {
public:
    BaseController() {}
    ~BaseController() {}

    virtual void initHandlers() {
        //listener.support(methods::GET, std::bind(&BaseController::handleGet, this, std::placeholders::_1));
        //listener.support(methods::POST, std::bind(&BaseController::handlePost, this, std::placeholders::_1));
    }

    pplx::task<void> open() {
        initHandlers();
        return listener.open();
    }
    pplx::task<void> close() { return listener.close(); }

    virtual void handleGet(http_request message) = 0;
    //virtual void handlePut(http_request message) = 0;
    virtual void handlePost(http_request message) = 0;
    //virtual void handleDelete(http_request message) = 0;
    //virtual void handlePatch(http_request messge) = 0;
    //virtual void handleHead(http_request message) = 0;
    //virtual void handleOptions(http_request message) = 0;
    //virtual void handleTrace(http_request message) = 0;
    //virtual void handleConnect(http_request message) = 0;
    //virtual void handleMerge(http_request message) = 0;

    void setEndPoint(const std::string & value) {
        uri endpointURI(value);
        uri_builder endpointBuilder;

        endpointBuilder.set_scheme(endpointURI.scheme());
        endpointBuilder.set_host(endpointURI.host());
        endpointBuilder.set_port(endpointURI.port());
        endpointBuilder.set_path(endpointURI.path());

        listener = http_listener(endpointBuilder.to_uri());
    }

protected:
    http_listener listener;
};
