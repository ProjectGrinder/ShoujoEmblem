#pragma once
#include "game/resources/srpg/state.h"

namespace Game::Srpg
{
    enum class Objective
    {
        ROUT, // Kill every single one of them
        KILL_TARGET, // Kill dood with ID X
        OBJECTIVE, // Sit on the objective with ID X
        SURVIVE, // Survive X turns
    };

    struct TurnState
    {
        TurnControlState phase = TurnControlState::WAITING_FOR_INPUT;
        int turnNumber = 0;
        bool isPlayerTurn = false;

        [[nodiscard]] bool isActive() const
        {
            switch (phase)
            {
                case TurnControlState::WAITING_FOR_INPUT:
                    return true;
                default:
                    return false;
            }
        }
    };

    struct SelectionState
    {
        CommandType action = CommandType::NONE;
        System::ECS::pid selectedUnit = static_cast<System::ECS::pid>(-1);
        System::ECS::pid selectedTarget = static_cast<System::ECS::pid>(-1);
    };

    struct BattleState
    {
        BattlePhase phase = BattlePhase::BEGIN;
        System::ECS::pid attacker = static_cast<System::ECS::pid>(-1);
        System::ECS::pid defender = static_cast<System::ECS::pid>(-1);
        // TODO: Data needed to resolve battle goes here
    };

    struct CampaignState
    {
        Objective winObjective;
        Objective loseObjective;

        int progressionStage;
        std::vector<std::pair<Objective, Objective>> objectives;

        explicit CampaignState(const std::vector<std::pair<Objective, Objective>> &objs)
        {
            objectives = objs;
            if (!objectives.empty())
            {
                winObjective = objectives[0].first;
                loseObjective = objectives[0].second;
                progressionStage = 0;
            }
        }
    };

    struct MapResource
    {
        int width{};
        int height{};
        std::vector<TerrainId> terrain{};
    };

    struct BoardState
    {
        TurnState turn_state;
        SelectionState selection_state;
        BattleState battle_state;
        CampaignState campaign_state;
        MapResource map_resource;
        BoardState() : campaign_state({}) {}
    };

}