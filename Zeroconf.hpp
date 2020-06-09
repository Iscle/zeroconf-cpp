//
// Created by iscle on 9/6/20.
//

#ifndef CPPOTIFY_ZEROCONF_HPP
#define CPPOTIFY_ZEROCONF_HPP

#include <string>
#include <unordered_set>
#include "Service.hpp"
#include "PacketListener.hpp"

class Zeroconf {
public:
    Zeroconf();

    static std::string getOrCreateLocalHostName();

    Zeroconf &setUseIpv4(bool ipv4);

    Zeroconf &setUseIpv6(bool ipv6);

    ~Zeroconf();

    Zeroconf &addReceiveListener();

    Zeroconf &removeReceiveListener();

    Zeroconf &addSendListener();

    Zeroconf &removeSendListener();

    Zeroconf &addNetworkInterfaces();

    Zeroconf &removeNetworkInterfaces();

    Zeroconf &addAllNetworkInterfaces();

    std::string getDomain();

    Zeroconf &setDomain(std::string &domain);

    std::string getLocalHostName();

    Zeroconf &setLocalHostName(std::string name);

    void getLocalAddresses();

    void send();

    std::vector<Record> getRegistry();

    void getAnnouncedServices();

    void announce(Service &service);

    void unannounce(Service &service);

private:
    static const std::string DISCOVERY;

    //static const int BROADCAST4;
    //static const int BROADCAST6;
    //const int thread;
    const std::vector<Record> registry;
    const std::unordered_set<Service> services;
    const std::vector<PacketListener *> receiveListeners;
    const std::vector<PacketListener *> sendListeners;
    bool useIpv4 = true;
    bool useIpv6 = true;
    std::string hostname;
    std::string domain;

    void handlePacket();

    bool probe(std::string &fqdn);

};

const std::string Zeroconf::DISCOVERY = "_services._dns-sd._udp.local";


#endif //CPPOTIFY_ZEROCONF_HPP
