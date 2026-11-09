#pragma once
#include "game/resources/srpg/item.h"

namespace Game::Srpg
{
    struct Inventory
    {
        std::vector<ItemInstance> items;
        Inventory() = default;
    };
}