#include <gmock/gmock.h>
#include "CardMock.hpp"
#include "DiscountProviderMock.hpp"
#include "Payment.h"

using namespace ::testing;

class PaymentTest : public Test {
public:
    virtual void SetUp()
    {
        cardMock = std::make_unique<CardMock>();
        discountProviderMock = std::make_unique<DiscountProviderMock>();
    }

    void createPaymentUnderTest()
    {
        payment = std::make_unique<Payment>(std::move(cardMock), std::move(discountProviderMock));
    }
    std::unique_ptr<CardMock> cardMock;
    std::unique_ptr<DiscountProviderMock> discountProviderMock;
    std::unique_ptr<Payment> payment;
};

TEST_F(PaymentTest, can_create_payment)
{

}
