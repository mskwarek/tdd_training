#pragma once

#include "IDiscountProvider.h"

class DiscountProvider : public IDiscountProvider {
public:
    virtual int getDiscount(const std::string&) override;
};
