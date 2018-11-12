#pragma once

#include <memory>
#include "ICard.h"
#include "IDiscountProvider.h"

class Payment {
public:
    Payment(std::unique_ptr<ICard>, std::unique_ptr<IDiscountProvider>);
    virtual ~Payment() = default;
    void processPayment();
private:
    std::unique_ptr<ICard> card_;
    std::unique_ptr<IDiscountProvider> discountProvider_;
};
