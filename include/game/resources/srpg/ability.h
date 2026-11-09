#pragma once
#include "effect.h"

namespace Game::Srpg
{
    enum class TurnPhase
    {
        // Inactive
        WAITING,
        // Active
        SELECT_UNIT,
        SELECT_COMMAND,
        // Move Command
        MOVING,
        // Fight Command
        SELECT_FIGHT_TARGET,
        SELECT_BATTLE_SKILL,
        FIGHTING,
        // Field Skill Command
        SELECT_FIELD_SKILL,
        SELECT_FIELD_SKILL_TARGET,
        FIELD_SKILLING,
        // Field Item Command
        SELECT_ITEM,
        SELECT_ITEM_TARGET,
        USING_ITEM,
        // Refresh (Dance/Sing)
        REFRESHING_UNIT,
    };

    using AbilityId = uint32_t;

    struct AbilityDefinition
    {
        TurnPhase onPhase;
        std::vector<Effect> effects;
    };
}