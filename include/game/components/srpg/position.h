#pragma once

namespace Game::Srpg
{
    struct Position
    {
        int x, y;
        Position(const int x, const int y) : x(x), y(y) {}
        Position() : x(0), y(0) {}
    };
}