#pragma once

#include <string>

class ICard {
public:
    virtual ~ICard() = default;
    virtual std::string getCardNumber() = 0;
};