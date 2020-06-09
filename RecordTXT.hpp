//
// Created by iscle on 9/6/20.
//

#ifndef CPPOTIFY_RECORDTXT_HPP
#define CPPOTIFY_RECORDTXT_HPP


#include <unordered_map>
#include "Record.hpp"

class RecordTXT : public Record {
public:
    RecordTXT();

    RecordTXT(std::string name, std::unordered_map<std::string, std::string> values);

    RecordTXT(std::string name, std::string map);

    std::list<std::pair<std::string, std::string>> getValues();

protected:
    void readData(int len, std::stringbuf &in);

    int writeData(std::stringbuf &out, Packet &packet);

private:
    std::unordered_map<std::string, std::string> values;
};


#endif //CPPOTIFY_RECORDTXT_HPP
