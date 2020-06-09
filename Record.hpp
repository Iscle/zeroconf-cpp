//
// Created by iscle on 9/6/20.
//

#ifndef CPPOTIFY_RECORD_HPP
#define CPPOTIFY_RECORD_HPP


#include <string>
#include <vector>
#include "Packet.hpp"

class Record {
public:
    enum Type {
        A = 0x01,
        PTR = 0x0C,
        CNAME = 0x05,
        TXT = 0x10,
        AAAA = 0x1C,
        SRV = 0x21,
        NSEC = 0x2F,
        ANY = 0xFF,
    };

    Type type;

    Record(Type type);

    Record *readAnswer(std::stringbuf &in);

    Record *readQuestion(std::stringbuf &in);

    std::string getName();

    Record &setName(std::string name);

    Type getType();

    Record *setTTL(int ttl);

    bool isUnicastQuery();

    void write(std::stringbuf &out, Packet &packet);

protected:
    int ttl;

    static int writeName(std::string &name, std::stringbuf &out, Packet &packet);

    static std::string readName(std::stringbuf &in);

    void readData(int len, std::stringbuf &in);

    int writeData(std::stringbuf &out, Packet &packet);

private:
    std::string name;
    int clazz;
    std::vector<unsigned char> data;

    static Record *getInstance(Type type);
};


#endif //CPPOTIFY_RECORD_HPP
