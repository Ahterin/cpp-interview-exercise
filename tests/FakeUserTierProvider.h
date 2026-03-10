#pragma once

#include <stdexcept>
#include <string>
#include <unordered_map>

#include "IUserTierProvider.h"

class FakeUserTierProvider : public IUserTierProvider {
   public:
    void setTier(const std::string& userId, UserTier tier) { m_tiers[userId] = tier; }

    [[nodiscard]] UserTier getUserTier(const std::string& userId) const override {
        const auto found = m_tiers.find(userId);
        if (found == m_tiers.end()) {
            throw std::runtime_error("Unknown user");
        }

        return found->second;
    }

   private:
    std::unordered_map<std::string, UserTier> m_tiers;
};
