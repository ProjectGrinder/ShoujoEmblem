#pragma once

namespace Game::Srpg
{
    struct EquipmentSlot
    {
        EquipmentSlotId id{};
        std::optional<EquipmentDefinition> equipped;
    };

    struct Equipment
    {
        std::vector<EquipmentSlot> slots;
        Equipment() = default;
    };
}