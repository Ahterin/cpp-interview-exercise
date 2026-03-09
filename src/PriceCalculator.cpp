#include "PriceCalculator.h"

PriceCalculator::PriceCalculator(const IUserTierProvider& userTierProvider)
    : m_userTierProvider(userTierProvider)
{
}

double PriceCalculator::calculateFinalPrice(const std::string& userId, double basePrice) const
{
    const auto tier = m_userTierProvider.getUserTier(userId);

    double discount = 0.0;

    if (tier == UserTier::Premium)
    {
        discount = 0.10;
    }
    else if (tier == UserTier::VIP)
    {
        discount = 0.25;
    }

    return basePrice - (basePrice * discount);
}
