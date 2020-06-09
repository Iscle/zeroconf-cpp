//
// Created by iscle on 9/6/20.
//

#include <memory>
#include "Record.hpp"
#include "RecordA.hpp"
#include "RecordAAAA.hpp"
#include "RecordSRV.hpp"
#include "RecordPTR.hpp"
#include "RecordTXT.hpp"
#include "RecordANY.hpp"

Record::Record(Record::Type type) {
    this->type = type;
    setTTL(4500);
    this->clazz = 1;
}

Record *Record::readAnswer(std::stringbuf &in) {
    std::string name = readName(in);
    Type type = A;//in.getShort() & 0xFFFF;
    Record *record = getInstance(type);
    record->setName(name);
    record->clazz = 0;//in.getShort() & 0xFFFF;
    record->ttl = 0;//in.getInt();
    int len = 0;//in.getShort() & 0xFFFF;
    record->readData(len, in);
    return record;
}

Record *Record::readQuestion(std::stringbuf &in) {
    std::string name = readName(in);
    Type type = A;//in.getShort() & 0xFFFF;
    Record *record = getInstance(type);
    record->setName(name);
    record->clazz = 0;//in.getShort() & 0xFFFF;
    return record;
}

std::string Record::getName() {
    return name;
}

Record &Record::setName(std::string name) {
    this->name = name;
    return *this;
}

Record::Type Record::getType() {
    return type;
}

Record *Record::setTTL(int ttl) {
    this->ttl = ttl;
    return this;
}

bool Record::isUnicastQuery() {
    return (clazz & 0x80) != 0;
}

void Record::write(std::stringbuf &out, Packet &packet) {
    writeName(name, out, packet);
    //out.putShort((short) type);
    //out.putShort((short) clazz);
    //out.putInt(ttl);
    int pos = 0;//out.position();
    //out.putShort((short) 0);
    int len = writeData(out, packet);
    //if (len > 0) out.putShort(pos, (short) len);
    //else out.position(pos);
}

int Record::writeName(std::string &name, std::stringbuf &out, Packet &packet) {
    int len = name.length();
    int start = 0;
    for (int i = 0; i <= len; i++) {
        char c = i == len ? '.' : name[i];
        if (c == '.') {
            //out.put((byte) (i - start));
            //for (int j = start; j < i; j++)
            //    out.put((byte) name.charAt(j));

            start = i + 1;
        }
    }

    //out.put((byte) 0);
    return name.length() + 2;
}

std::string Record::readName(std::stringbuf &in) {
    std::string ret;
    int len;
    /*while ((len = (in.get() & 0xFF)) > 0) {
        if (len < 0x40) {
            if (ret.length() > 0) ret.push_back('.');
            while (len-- > 0) ret.push_back((char) (in.get() & 0xFF));
        } else {
            int off = ((len & 0x3F) << 8) | (in.get() & 0xFF);       // Offset from start of packet
            len = (in.get(off++) & 0xFF);
            while (len-- > 0) ret.push_back((char) (in.get(off++) & 0xFF));
            break;
        }
    }*/
    return ret;
}

void Record::readData(int len, std::stringbuf &in) {
    data = std::vector<unsigned char>(len);
    //in.get(data);
}

int Record::writeData(std::stringbuf &out, Packet &packet) {
    if (!data.empty()) {
        //out.put(data);
        return data.size();
    } else {
        return -1;
    }
}

Record *Record::getInstance(Record::Type type) {
    switch (type) {
        case A:
            return new RecordA();
        case AAAA:
            return new RecordAAAA();
        case SRV:
            return new RecordSRV();
        case PTR:
            return new RecordPTR();
        case TXT:
            return new RecordTXT();
        case ANY:
            return new RecordANY();
        default:
            return new Record(type);
    }
}
