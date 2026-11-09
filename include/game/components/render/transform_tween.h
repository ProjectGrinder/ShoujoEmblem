#pragma once
#include "game/utils/tween_util.h"

namespace Game::Render
{

    struct TransformTweenData
    {
        Math::Point from;
        Math::Point to;
        float duration;
        float elapsed;
        EaseType ease;
    };

    struct TransformTweenComponent
    {
        TransformTweenData positionTween;
        TransformTweenData rotationTween;
        TransformTweenData scaleTween;
        bool positionTweenActive;
        bool rotationTweenActive;
        bool scaleTweenActive;

        [[nodiscard]] bool isActive() const
        {
            return positionTweenActive || rotationTweenActive || scaleTweenActive;
        }
    };
}