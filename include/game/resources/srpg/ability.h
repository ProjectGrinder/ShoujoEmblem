#pragma once
#include "effect.h"
#include "state.h"

namespace Game::Srpg
{
    using AbilityId = uint32_t;

    struct AbilityDefinition
    {
        ActionType onAction;
        std::vector<Effect> effects;
    };
}