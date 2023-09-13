#include "Request.h"

std::string Request::toFile()
{
    return std::to_string(m_senderID) + ',' + std::to_string(m_receiverID) + '\n';
}