//
// Created by iscle on 9/6/20.
//

#ifndef CPPOTIFY_ZEROCONF_HPP
#define CPPOTIFY_ZEROCONF_HPP

#include <string>

class Zeroconf {
public:
    static const std::string DISCOVERY;
    Zeroconf();
    static std::string getOrCreateLocalHostName();
    Zeroconf setUseIpv4(bool ipv4);
    Zeroconf setUseIpv6(bool ipv6);
    ~Zeroconf();
    Zeroconf addReceiveListener();
    Zeroconf removeReceiveListener();
    Zeroconf addSendListener();
    Zeroconf removeSendListener();
    Zeroconf addNetworkInterfaces();
    Zeroconf removeNetworkInterfaces();
    Zeroconf addAllNetworkInterfaces();
    std::string getDomain();
    Zeroconf setDomain(std::string domain);
    std::string getLocalHostName();
    Zeroconf setLocalHostName(std::string name);
    void getLocalAddresses();
    void send();
    void getRegistry();
    void getAnnouncedServices();
    void announce();
    void unannounce();

private:
    void handlePacket();
    bool probe(std::string fqdn);

};

const std::string Zeroconf::DISCOVERY = "_services._dns-sd._udp.local";


#endif //CPPOTIFY_ZEROCONF_HPP
