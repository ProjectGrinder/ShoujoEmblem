#pragma once

// define scenes
namespace Scene
{

    struct Demo;

    template <typename T>
    void queue_change_scene();
    void switch_to_level(int level);
}