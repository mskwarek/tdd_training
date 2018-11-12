#pragma once

#include "IDiscountProvider.h"

class DiscountProviderMock : public IDiscountProvider {
public:
    MOCK_METHOD1(getDiscount, int(const std::string&));
};
