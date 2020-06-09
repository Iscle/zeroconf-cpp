//
// Created by iscle on 9/6/20.
//

#ifndef CPPOTIFY_SERVICE_HPP
#define CPPOTIFY_SERVICE_HPP


#include <string>
#include <map>
#include <list>
#include <unordered_map>
#include "Packet.hpp"

class Service {
public:
    Service(std::string &alias, std::string &service, int port);

    Service *setProtocol(std::string &protocol);

    std::string getDomain();

    Service *setDomain(std::string domain);

    std::string getHost();

    Service *setHost(std::string host);

    Service *setText(std::string text);

    Service *setText(std::unordered_map<std::string, std::string> &text);

    Service *putText(std::string &key, std::string &value);

    Service *addAddress(int address);

    Service *addAddresses();

    bool hasAddresses();

    std::string getAlias();

    std::string getInstanceName();

    std::string getServiceName();

    Packet getPacket();

private:
    std::string alias;
    std::string service;
    int port;
    std::unordered_map<std::string, std::string> text;
    std::list<int> addresses;
    std::string domain;
    std::string protocol;
    std::string host;

    static void esc(std::string &in, std::string &out);
};


#endif //CPPOTIFY_SERVICE_HPP
