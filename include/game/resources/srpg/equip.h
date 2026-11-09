#pragma once

namespace Game::Srpg
{
    using EquipmentSlotId = uint32_t;
    using EquipmentId = uint32_t;

    struct EquipmentDefinition
    {
        std::string name;
        std::string definition;
        EquipmentSlotId slot_id;
        std::vector<Effect> effects;
    };
}