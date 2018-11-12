#include "PrimeFactors.h"
#include <gmock/gmock.h>

TEST(primeFactorsTest, testPrimeFactorsOfSomeIntegers)
{
    using namespace ::testing;

    EXPECT_THAT(PrimeFactors::getPrimeFactors(1), ElementsAre());
}
