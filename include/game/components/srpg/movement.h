#pragma once

namespace Game::Srpg
{
    struct Movement
    {
        int mov_unit;
        int mov_used;
        Movement() = default;
        explicit Movement(const int mov_unit) : mov_unit(mov_unit), mov_used(0) {}
    };
}