#pragma once

#include "game/resources/srpg/action.h"
#include "game/resources/srpg/ability.h"
#include "game/resources/srpg/equip.h"
#include "game/resources/srpg/item.h"

namespace Game::Srpg
{
    using ActorId = uint32_t;

    struct ActorDefinition
    {
        std::string name;
        std::string description;

        struct StatSpread {
            int hp{};
            int strength{};
            int magic{};
            int defense{};
            int speed{};
            int mastery{};
            int critRate{};
            int critDmg{};
            int luck{};
        };

        StatSpread startingStats;
        StatSpread statGrowths;

        std::vector<ItemInstance> initialItems;
        std::vector<EquipmentDefinition> initialEquipment;
        std::vector<ActionDefinition> initialActions;
        std::vector<AbilityDefinition> initialAbilities;
    };
}