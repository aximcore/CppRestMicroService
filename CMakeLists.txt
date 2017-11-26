cmake_minimum_required(VERSION 3.7)
project(CppRestMicroService)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(cpprest 2.9.1 REQUIRED)
find_package(Boost REQUIRED COMPONENTS system thread log program_options chrono)
find_package(Threads REQUIRED)
find_package(OpenSSL 1.0.1 REQUIRED)

add_executable(CppRestMicroService
    signal/SignalHandler.hpp
    controller/EchoController.hpp
    controller/BaseController.hpp
    main.cpp)
target_link_libraries(CppRestMicroService PRIVATE ${CPP_REST_LIBRARY} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES})
