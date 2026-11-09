#pragma once

namespace Game::Srpg
{
    using EffectId = uint32_t;

    struct Effect
    {
        EffectId id;
        std::vector<int> parameters;
    };
}