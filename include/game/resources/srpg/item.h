#pragma once
#include "effect.h"

namespace Game::Srpg
{
    using ItemId = uint32_t;

    enum class ItemCategory
    {
        Consumable,
        Equipment,
        Quest,
        Misc,
    };

    enum class ItemTargetType
    {
        None,
        Self,
        Ally, // parameter is 1 = ALL allies affected
        Enemy, // parameter is 1 = ALL enemies affected
        Range, // parameter is range of effect
        Selected,
        Area, // parameter is area of effect
    };

    struct ItemTarget
    {
        ItemTargetType type;
        int parameter;
    };

    struct ItemInstance
    {
        ItemId id;
        int uses;
    };

    struct ItemDefinition
    {
        std::string name;
        std::string description;
        int uses;
        ItemCategory category;
        ItemTarget target;
        std::vector<Effect> effects;
    };
}