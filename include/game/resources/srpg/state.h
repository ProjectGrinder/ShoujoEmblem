#pragma once

namespace Game::Srpg
{
    enum class InputPhase
    {
        NONE,                   // Input disabled / non-interactive
        SELECT_UNIT,            // Selecting an active unit on the map
        SELECT_COMMAND,         // Choosing an action (Move, Attack, Skill, Item, Wait)
        SELECT_MOVE_TARGET,     // Picking movement tile
        SELECT_FIGHT_TARGET,    // Picking attack target
        SELECT_BATTLE_SKILL,    // Choosing a combat skill
        SELECT_FIELD_SKILL,     // Choosing a field skill
        SELECT_FIELD_SKILL_TARGET,
        SELECT_ITEM,
        SELECT_ITEM_TARGET,
        SELECT_REFRESH_TARGET,
    };

    enum class CommandType
    {
        NONE,
        MOVE,
        COMBAT,
        FIELD_SKILL,
        USE_ITEM,
        REFRESH,
    };

    enum class TurnControlState
    {
        WAITING_FOR_INPUT,  // Player is navigating menus / selecting targets
        EXECUTING_ACTION,   // System is animating / resolving action
        AI_TURN,            // Non-player turn / external processing
    };

    enum class BattlePhase
    {
        NONE, // No combat
        BEGIN, // Enter combat
        ABILITY, // Resolve rendering ability triggers
        COMBAT, // Roll accuracy and render damage
        END, // Exit combat
    };
}