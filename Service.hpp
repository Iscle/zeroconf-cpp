//
// Created by iscle on 9/6/20.
//

#ifndef CPPOTIFY_SERVICE_HPP
#define CPPOTIFY_SERVICE_HPP


#include <string>
#include <map>
#include <list>

class Service {
public:

private:
    const std::string alias;
    const std::string service;
    const int port;
    const std::map<std::string, std::string> text;
    const std::list<int> addresses;
    std::string domain;
    std::string protocol;
    std::string host;
};


#endif //CPPOTIFY_SERVICE_HPP
