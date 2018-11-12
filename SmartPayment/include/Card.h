#pragma once

#include "ICard.h"

class Card : public ICard {
public:
    virtual std::string getCardNumber() override;
};
