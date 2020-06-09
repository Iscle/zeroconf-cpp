//
// Created by iscle on 9/6/20.
//

#ifndef CPPOTIFY_PACKET_HPP
#define CPPOTIFY_PACKET_HPP


#include <list>
#include <string>
#include "Record.hpp"

class Packet {
public:
    Packet();

    Packet(int id);

    int getAddress();

    void setAddress(int address);

    int getID();

    bool isResponse();

    void setResponse(bool on);

    bool isAuthoritative();

    void setAuthoritative(bool on);

    void read(int in, int address);

    void write(int out);

    std::string toString();

    std::list<int> getQuestions();

    std::list<int> getAnswers();

    std::list<int> getAdditionals();

    void addAnswer(Record *record);

    void addQuestion(Record *record);

    void addAdditional(int record);

    void addAuthority(int record);

private:
    static constexpr int FLAG_RESPONSE = 15;
    static constexpr int FLAG_AA = 10;
    const std::list<int> questions;
    const std::list<int> answers;
    const std::list<int> authorities;
    const std::list<int> additionals;
    int id;
    int flags;
    int address;

    bool isFlag(int flag);

    void setFlag(int flag, bool on);
};


#endif //CPPOTIFY_PACKET_HPP
