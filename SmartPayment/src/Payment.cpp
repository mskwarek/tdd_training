#include "Payment.h"

Payment::Payment(std::unique_ptr<ICard> card, std::unique_ptr<IDiscountProvider> provider)
    : card_(std::move(card)), discountProvider_(std::move(provider))
{}

void Payment::processPayment()
{

}