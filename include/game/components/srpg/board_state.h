#pragma once

namespace Game::Srpg
{
    enum class Objective
    {
        // Kill every single one of them
        ROUT,
        // Kill dood with ID X
        KILL_TARGET,
        // Sit on the objective with ID X
        OBJECTIVE,
        // Survive X turns
        SURVIVE,
    };

    enum class BattlePhase
    {
        // Enter combat
        BEGIN,
        // Resolve rendering ability triggers
        ABILITY,
        // Roll accuracy and calculate damage
        COMBAT,
        // Resolve rendering animations
        RESOLVE,
        // End, remove abilities that go out of scope
        END,
    };

    struct TurnState
    {
        TurnPhase phase = TurnPhase::WAITING;
        int turnNumber = 0;
        bool isPlayerTurn = false;

        [[nodiscard]] bool isActive() const
        {
            switch (phase)
            {
                case TurnPhase::WAITING:
                case TurnPhase::MOVING:
                case TurnPhase::FIGHTING:
                case TurnPhase::FIELD_SKILLING:
                case TurnPhase::USING_ITEM:
                case TurnPhase::REFRESHING_UNIT:
                    return false;
                default:
                    return true;
            }
        }
    };

    struct SelectionState
    {
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