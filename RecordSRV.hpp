//
// Created by iscle on 9/6/20.
//

#ifndef CPPOTIFY_RECORDSRV_HPP
#define CPPOTIFY_RECORDSRV_HPP


#include "Record.hpp"

class RecordSRV : public Record {
public:
    RecordSRV();

    RecordSRV(std::string name, std::string target, int port);

    int getPriority();

    int getWeight();

    int getPort();

    std::string getTarget();

private:
    int priority;
    int weight;
    int port;
    std::string target;
};


#endif //CPPOTIFY_RECORDSRV_HPP
