//
// Created by iscle on 9/6/20.
//

#include <iostream>
#include "Zeroconf.hpp"

Zeroconf::Zeroconf() {
    setDomain(".local");

    //try {
    setLocalHostName(getOrCreateLocalHostName());
    //}
}

std::string Zeroconf::getOrCreateLocalHostName() {
    std::string host = "localhost";//InetAddress.getLocalHost().getHostName();
    if (host == "localhost") {
        host = "changeme.local";
        std::cout << "Hostname cannot be `localhost`, temporary hostname is " << host << "." << std::endl;
    }
}

Zeroconf &Zeroconf::setUseIpv4(bool ipv4) {
    this->useIpv4 = ipv4;
    return *this;
}

Zeroconf &Zeroconf::setUseIpv6(bool ipv6) {
    this->useIpv6 = ipv6;
    return *this;
}

Zeroconf::~Zeroconf() {
    for (Service service : services)
        unannounce(service);

    // TODO: End thread
}

Zeroconf &Zeroconf::addReceiveListener() {
    // TODO
    return *this;
}

Zeroconf &Zeroconf::removeReceiveListener() {
    // TODO
    return *this;
}

Zeroconf &Zeroconf::addSendListener() {
    return *this;
}

Zeroconf &Zeroconf::removeSendListener() {
    // TODO
}

Zeroconf &Zeroconf::addNetworkInterfaces() {
    return *this;
}

Zeroconf &Zeroconf::removeNetworkInterfaces() {
    return *this;
}

Zeroconf &Zeroconf::addAllNetworkInterfaces() {
    return *this;
}

std::string Zeroconf::getDomain() {
    return domain;
}

Zeroconf &Zeroconf::setDomain(std::string &domain) {
    this->domain = domain;
    return *this;
}

std::string Zeroconf::getLocalHostName() {
    return std::string();
}

Zeroconf &Zeroconf::setLocalHostName(std::string name) {
    return *this;
}

void Zeroconf::getLocalAddresses() {

}

void Zeroconf::send() {

}

std::vector<Record> Zeroconf::getRegistry() {

}

void Zeroconf::getAnnouncedServices() {

}

void Zeroconf::announce(Service &service) {
    if (service.getDomain().empty())
        service.setDomain(getDomain());
    if (service.getHost().empty())
        service.setHost(getLocalHostName());
    //if (!service.hasAddresses())
    //    service.addAddresses(getLocalAddresses());

    Packet packet = service.getPacket();
    if (probe(service.getInstanceName()))
        throw std::invalid_argument("Service " + service.getInstanceName() + " already on network");

    //getRegistry().
}

void Zeroconf::unannounce(Service &service) {

}

void Zeroconf::handlePacket() {

}

bool Zeroconf::probe(std::string &fqdn) {
    return false;
}
