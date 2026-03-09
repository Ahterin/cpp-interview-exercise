#pragma once

#include "IUserTierProvider.h"

#include <string>

class PriceCalculator
{
public:
    explicit PriceCalculator(const IUserTierProvider& userTierProvider);

    double calculateFinalPrice(const std::string& userId, double basePrice) const;

private:
    const IUserTierProvider& m_userTierProvider;
};
