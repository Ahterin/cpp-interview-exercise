#include <gtest/gtest.h>

#include <stdexcept>

#include "FakeUserTierProvider.h"
#include "PriceCalculator.h"

namespace {
constexpr double kEpsilon = 1e-9;
}  // namespace

TEST(PriceCalculatorTests, RegularUserKeepsOriginalPrice) {
    FakeUserTierProvider provider;
    provider.setTier("alice", UserTier::Regular);

    const PriceCalculator calculator(provider);
    const double finalPrice = calculator.calculateFinalPrice("alice", 100.0);

    EXPECT_NEAR(finalPrice, 100.0, kEpsilon);
}

TEST(PriceCalculatorTests, PremiumUserGetsTenPercentDiscount) {
    FakeUserTierProvider provider;
    provider.setTier("bob", UserTier::Premium);

    const PriceCalculator calculator(provider);
    const double finalPrice = calculator.calculateFinalPrice("bob", 100.0);

    EXPECT_NEAR(finalPrice, 90.0, kEpsilon);
}

TEST(PriceCalculatorTests, ZeroPriceForPremiumUser) {
    FakeUserTierProvider provider;
    provider.setTier("zero", UserTier::Premium);

    const PriceCalculator calculator(provider);
    const double finalPrice = calculator.calculateFinalPrice("zero", 0.0);

    EXPECT_NEAR(finalPrice, 0.0, kEpsilon);
}

TEST(PriceCalculatorTests, UnknownUserThrows) {
    FakeUserTierProvider provider;
    const PriceCalculator calculator(provider);

    EXPECT_THROW(calculator.calculateFinalPrice("missing-user", 100.0), std::runtime_error);
}
