//
// Created by iscle on 9/6/20.
//

#include <vector>
#include "Service.hpp"
#include "Utils.hpp"
#include "RecordPTR.hpp"
#include "RecordSRV.hpp"
#include "RecordTXT.hpp"

Service::Service(std::string &alias, std::string &service, int port) : alias(alias) {
    this->alias = alias;
    for (int i = 0; i < alias.length(); i++) {
        char c = alias[i];
        if (c < 0x20 || c == 0x7F)
            throw std::invalid_argument(alias);
    }

    this->service = service;
    this->port = port;
    this->protocol = "tcp";
}

Service *Service::setProtocol(std::string &protocol) {
    if (protocol == "tcp" || protocol == "udp")
        this->protocol = protocol;
    else
        throw std::invalid_argument(protocol);

    return this;
}

std::string Service::getDomain() {
    return domain;
}

Service *Service::setDomain(std::string domain) {
    if (domain.length() < 2 || domain[0] != '.')
        throw std::invalid_argument(domain);

    this->domain = domain;
    return this;
}

std::string Service::getHost() {
    return host;
}

Service *Service::setHost(std::string host) {
    this->host = host;
    return this;
}

Service *Service::setText(std::string &text) {
    this->text.clear();
    std::vector<std::string> q = split(text, ", *");
    for (std::string s : q) {
        std::vector<std::string> r = split(s, "=");
        if (r.size() == 2)
            this->text.insert({r[0], r[1]});
        else
            throw std::invalid_argument(text);
    }

    return this;
}

Service *Service::setText(std::unordered_map<std::string, std::string> &text) {
    this->text.clear();
    this->text.insert(text.begin(), text.end());
    return this;
}

Service *Service::putText(std::string &key, std::string &value) {
    this->text.insert({key, value});
    return this;
}

Service *Service::addAddress(int address) {

}

Service *Service::addAddresses() {

}

bool Service::hasAddresses() {
    return !addresses.empty();
}

std::string Service::getAlias() {
    return alias;
}

std::string Service::getInstanceName() {
    std::string ret;
    esc(alias, ret);
    ret.append("._");
    esc(service, ret);
    ret.append("._");
    ret.append(protocol);
    ret.append(domain);
    return ret;
}

std::string Service::getServiceName() {
    std::string ret;
    ret.push_back('_');
    esc(service, ret);
    ret.append("._");
    ret.append(protocol);
    ret.append(domain);
    return ret;
}

Packet Service::getPacket() {
    Packet packet;
    packet.setAuthoritative(true);

    std::string fqdn = getInstanceName();
    std::string ptrname = getServiceName();

    packet.addAnswer((new RecordPTR(ptrname, fqdn))->setTTL(28800));
    packet.addAnswer((new RecordSRV(fqdn, host, port))->setTTL(120));
    if (!text.empty())
        packet.addAnswer((new RecordTXT(fqdn, text))->setTTL(120));

    for (auto const &address : addresses) {

    }

    return packet;
}

void Service::esc(std::string &in, std::string &out) {
    for (char c : in) {
        if (c == '.' || c == '\\')
            out.push_back('\\');
        out.push_back(c);
    }
}

