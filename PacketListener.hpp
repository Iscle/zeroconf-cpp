//
// Created by iscle on 9/6/20.
//

#ifndef CPPOTIFY_PACKETLISTENER_HPP
#define CPPOTIFY_PACKETLISTENER_HPP

#include "Packet.hpp"

class PacketListener {
public:
    virtual void packetEvent(Packet &packet) = 0;
};

#endif //CPPOTIFY_PACKETLISTENER_HPP
