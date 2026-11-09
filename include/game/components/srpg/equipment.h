#pragma once
#include "inventory.h"

namespace Game::Srpg
{
    struct EquipmentSlot
    {
        int slot_id{};
        std::optional<ItemInstance> equipped;
    };

    struct Equipment
    {
        std::vector<EquipmentSlot> slots;
        Equipment() = default;
    };
}