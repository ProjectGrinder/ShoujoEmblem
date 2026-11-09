#pragma once

namespace Game::Srpg
{
    struct Health
    {
        int health;
        int max_health;

        Health() = default;
        explicit Health(const int max) : health(max), max_health(max) {}
    };
}