#pragma once

#include "ICard.h"

class CardMock : public ICard {
public:
    MOCK_METHOD0(getCardNumber, std::string());
};
