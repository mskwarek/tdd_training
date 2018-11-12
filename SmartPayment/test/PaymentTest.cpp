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
    createPaymentUnderTest();
}

TEST_F(PaymentTest, test_process_payment_flow)
{
    EXPECT_CALL(*cardMock, getCardNumber()).WillOnce(Return("1234 1243 2147821421"));
    EXPECT_CALL(*discountProviderMock, getDiscount(_));
    createPaymentUnderTest();

    payment->processPayment();
}

TEST_F(PaymentTest, the_card_number_from_card_reader_is_the_sam_that_is_passed_to_discount_provider)
{
    std::string sampleCardNumber = "123467821367812";
    EXPECT_CALL(*cardMock, getCardNumber()).WillOnce(Return(sampleCardNumber));
    EXPECT_CALL(*discountProviderMock, getDiscount(_)).WillOnce(
        DoAll(
            Invoke(
                [&](auto actualDiscount){
                    EXPECT_EQ(sampleCardNumber, actualDiscount);
                }
            ),
            Return(0)
        )
    );
    createPaymentUnderTest();

    payment->processPayment();
}
