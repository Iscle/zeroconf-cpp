//
// Created by iscle on 9/6/20.
//

#ifndef CPPOTIFY_RECORDAAAA_HPP
#define CPPOTIFY_RECORDAAAA_HPP


#include "Record.hpp"

class RecordAAAA : public Record {
public:
    RecordAAAA();

    RecordAAAA(std::string name, int value);

    int getAddresss();

private:
    std::vector<unsigned char> address;
};


#endif //CPPOTIFY_RECORDAAAA_HPP
