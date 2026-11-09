#pragma once

#include "game/components.h"
#include "system/input.h"

namespace Game
{
    template<typename T>
    void input_system(
            [[maybe_unused]] T &syscall,
            System::ECS::Query<Input> &input)
    {
        if (input.begin() == input.end())
            return;

        // TODO: Change fixed key bindings to be rebindable
        constexpr auto LEFT = 0x25;
        constexpr auto UP = 0x26;
        constexpr auto RIGHT = 0x27;
        constexpr auto DOWN = 0x28;

        constexpr auto W = 0x57;
        constexpr auto A = 0x41;
        constexpr auto S = 0x53;
        constexpr auto D = 0x44;
        constexpr auto Z = 0x5A;
        // constexpr auto X = 0x58;

        constexpr auto KEY1 = 0x58; // X
        constexpr auto KEY2 = 0x43; // C
        constexpr auto KEY3 = 0x4D; // M
        constexpr auto KEY4 = 0xBC; // ,

        constexpr auto ESC = 0x1B;
        constexpr auto SPACE = 0x20;
        constexpr auto TAB = 0x09;
        constexpr auto ENTER = 0x0D;
        constexpr auto SHIFT = 0x10;

        auto &input_c = input.front().get<Input>();

        // input stuff
    }
} // namespace Game::Battle
