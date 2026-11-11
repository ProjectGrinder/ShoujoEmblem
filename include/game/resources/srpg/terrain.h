#pragma once

namespace Game::Srpg
{
    using TerrainId = uint32_t;

    struct Terrain
    {
        std::string name;
        int moveCost;
    };
}