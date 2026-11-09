#pragma once

namespace Game::Srpg
{

    struct ItemInstance
    {
        int item_id;
        int uses;
    };

    struct Inventory
    {
        std::vector<ItemInstance> items;
        Inventory() = default;
    };
}