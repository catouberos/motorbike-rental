#include <iostream>
#ifndef REQUEST_H
#define REQUEST_H
class Request
{
    int m_senderID{};
    int m_receiverID{};

public: 
    Request() = default;
    Request(int senderID, int receiverID)
        :m_senderID{senderID}, m_receiverID{receiverID}{}

    friend class System;
    
    std::string toFile();
};
#endif