#pragma once
#include "effect.h"

namespace Game::Srpg
{

    enum class ActionType
    {
        HEAL,
        BUFF,
        DEBUFF,
        PHY,
        MAG, // use character element as base
    };

    enum class ActionTarget
    {
        SELF,
        ALLY,
        ENEMY,
        ALLY_ALL,
        ENEMY_ALL,
        ALL,
    };

    using ActionId = uint32_t;

    struct ActionDefinition {
        std::string name;
        std::string description;

        ActionType type;
        ActionTarget target;

        int minimumRange;
        int maximumRange;

        std::vector<Effect> effects{};
    };
}