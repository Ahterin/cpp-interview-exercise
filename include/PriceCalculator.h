#pragma once

#include <string>

#include "IUserTierProvider.h"

class PriceCalculator {
   public:
    explicit PriceCalculator(const IUserTierProvider& userTierProvider);

    [[nodiscard]] double calculateFinalPrice(const std::string& userId, double basePrice) const;

   private:
    const IUserTierProvider& m_userTierProvider;
};
