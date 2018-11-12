#pragma once

#include <string>

class IDiscountProvider {
public:
    virtual ~IDiscountProvider() = default;
    virtual int getDiscount(const std::string&) = 0;
};
