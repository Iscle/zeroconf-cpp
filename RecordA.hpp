//
// Created by iscle on 9/6/20.
//

#ifndef CPPOTIFY_RECORDA_HPP
#define CPPOTIFY_RECORDA_HPP


#include "Record.hpp"

class RecordA : public Record {
public:
    RecordA();

    RecordA(std::string name, int address);

    int getAddress();
};


#endif //CPPOTIFY_RECORDA_HPP
