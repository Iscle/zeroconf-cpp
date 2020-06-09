//
// Created by iscle on 9/6/20.
//

#ifndef CPPOTIFY_RECORDPTR_HPP
#define CPPOTIFY_RECORDPTR_HPP


#include "Record.hpp"

class RecordPTR : public Record {
public:
    RecordPTR();

    RecordPTR(std::string name, std::string value);

    RecordPTR(std::string name);

    std::string getValue();

private:
    std::string value;
};


#endif //CPPOTIFY_RECORDPTR_HPP
