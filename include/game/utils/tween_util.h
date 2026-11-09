#pragma once
#include <cmath>

#include "constant.h"
namespace Game::Render
{
    inline float easeInSine(const float progress)
    {
        return 1 - std::cos(progress * PI / 2);
    }

    inline float easeOutSine(const float progress)
    {
        return std::sin(progress * PI / 2);
    }

    inline float easeInOutSine(const float progress)
    {
        return (1 - std::cos(progress * PI)) / 2;
    }

    inline float easeInQuad(const float progress)
    {
        return progress * progress;
    }

    inline float easeOutQuad(const float progress)
    {
        return 1 - (1 - progress) * (1 - progress);
    }

    inline float easeInOutQuad(const float progress)
    {
        return progress < 0.5 ? 2 * progress * progress : 1 - static_cast<float>(std::pow(-2 * progress + 2, 2)) / 2;
    }

    inline float easeInCubic(const float progress)
    {
        return progress * progress * progress;
    }

    inline float easeOutCubic(const float progress)
    {
        return 1 - static_cast<float>(std::pow(1 - progress, 3));
    }

    inline float easeInOutCubic(const float progress)
    {
        return progress < 0.5 ? 4 * progress * progress * progress : 1 - static_cast<float>(std::pow(-2 * progress + 2, 3)) / 2;
    }

    inline float easeInQuart(const float progress)
    {
        return progress * progress * progress * progress;
    }

    inline float easeOutQuart(const float progress)
    {
        return 1 - static_cast<float>(std::pow(1 - progress, 4));
    }

    inline float easeInOutQuart(const float progress)
    {
        return progress < 0.5 ? 8 * progress * progress * progress * progress : 1 - static_cast<float>(std::pow(-2 * progress + 2, 4)) / 2;
    }

    inline float easeInQuint(const float progress)
    {
        return progress * progress * progress * progress * progress;
    }

    inline float easeOutQuint(const float progress)
    {
        return 1 - static_cast<float>(std::pow(1 - progress, 5));
    }

    inline float easeInOutQuint(const float progress)
    {
        return progress < 0.5 ? 16 * progress * progress * progress * progress * progress : 1 - static_cast<float>(std::pow(-2 * progress + 2, 5)) / 2;
    }

    inline float easeInExpo(const float progress)
    {
        return progress == 0 ? 0 : static_cast<float>(std::pow(2, 10 * progress - 10));
    }

    inline float easeOutExpo(const float progress)
    {
        return progress == 1 ? 1 : static_cast<float>(1 - std::pow(2, -10 * progress));
    }

    inline float easeInOutExpo(const float progress)
    {
        return progress == 0 ? 0 : (
            progress == 1 ? 1 : (
                progress < 0.5 ? static_cast<float>(std::pow(2, 20 * progress - 10)) / 2 : 1 - static_cast<float>(std::pow(2, -20 * progress + 10)) / 2
            )
        );
    }

    inline float easeInCirc(const float progress)
    {
        return 1 - std::sqrt(1 - progress * progress);
    }

    inline float easeOutCirc(const float progress)
    {
        return std::sqrt(1 - progress * progress);
    }

    inline float easeInOutCirc(const float progress)
    {
        return progress < 0.5 ? (1 - std::sqrt(1 - 2 * progress * progress)) / 2 : (std::sqrt(1 - (2 * progress - 2) * (2 * progress - 2)) + 1) / 2;
    }

    inline float easeInBack(const float progress)
    {
        constexpr float c1 = 1.70158f;
        constexpr float c3 = c1 + 1;
        return c3 * progress * progress * progress - c1 * progress * progress;
    }

    inline float easeOutBack(const float progress)
    {
        constexpr float c1 = 1.70158f;
        constexpr float c3 = c1 + 1;
        return 1 + c3 * static_cast<float>(std::pow(progress - 1, 3)) + c1 * static_cast<float>(std::pow(progress - 1, 2));
    }

    inline float easeInOutBack(const float progress)
    {
        constexpr float c1 = 1.70158f;
        constexpr float c2 = c1 * 1.525f;
        return progress < 0.5 ? static_cast<float>(std::pow(2 * progress, 2) * ((c2 + 1) * 2 * progress - c2)) / 2.0f : static_cast<float>(std::pow(2 * progress - 2, 2) * ((c2 + 1) * (progress * 2 - 2) + c2) + 2) / 2.0f;
    }

    inline float easeInElastic(const float progress)
    {
        constexpr float c4 = (2 * PI) / 3.0f;

        return progress == 0.0f ? 0.0f : progress == 1.0f ? 1.0f : -static_cast<float>(std::pow(2, 10 * progress - 10) * std::sin((progress * 10 - 10.75) * c4));
    }

    inline float easeOutElastic(const float progress)
    {
        constexpr float c4 = (2 * PI) / 3.0f;
        return progress == 0.0f ? 0.0f : progress == 1.0f ? 1.0f : static_cast<float>(std::pow(2, -10 * progress) * std::sin((progress * 10 - 0.75) * c4)) + 1.0f;
    }

    inline float easeInOutElastic(const float progress)
    {
        constexpr float c5 = (2 * PI) / 4.5f;
        return progress == 0.0f ? 0.0f : progress == 1.0f ? 1.0f : progress < 0.5 ? -static_cast<float>(std::pow(2, 20 * progress - 10) * std::sin((20 * progress - 11.125) * c5)) / 2.0f : (static_cast<float>(std::pow(2, -20 * progress + 10) * std::sin((20 * progress - 11.125) * c5)) / 2.0f) + 1.0f;
    }

    inline float easeOutBounce(const float progress)
    {
        constexpr float n1 = 7.5625f;
        constexpr float d1 = 2.75f;

        if (progress < 1 / d1) {
            return n1 * progress * progress;
        }
        if (progress < 2 / d1)
        {
            return n1 * (progress - 1.5f / d1) * (progress - 1.5f) + 0.75f;
        }
        if (progress < 2.5 / d1)
        {
            return n1 * (progress - 2.25f / d1) * (progress - 2.25f) + 0.9375f;
        }
        return n1 * (progress - 2.625f / d1) * (progress - 2.625f) + 0.984375f;
    }

    inline float easeInBounce(const float progress)
    {
        return 1 - easeOutBounce(1 - progress);
    }

    inline float easeInOutBounce(const float progress)
    {
        return progress < 0.5f ? easeInBounce(progress * 2) / 2.0f : easeOutBounce(progress * 2 - 1) / 2.0f + 0.5f;
    }

    enum class EaseType
    {
        None,

        InSine,
        OutSine,
        InOutSine,

        InQuad,
        OutQuad,
        InOutQuad,

        InCubic,
        OutCubic,
        InOutCubic,

        InQuart,
        OutQuart,
        InOutQuart,

        InQuint,
        OutQuint,
        InOutQuint,

        InExpo,
        OutExpo,
        InOutExpo,

        InCirc,
        OutCirc,
        InOutCirc,

        InBack,
        OutBack,
        InOutBack,

        InElastic,
        OutElastic,
        InOutElastic,

        InBounce,
        OutBounce,
        InOutBounce,
    };

    inline float applyEase(const EaseType type, const float progress)
    {
        switch (type)
        {
        case EaseType::InSine:
            return easeInSine(progress);
            break;
        case EaseType::OutSine:
            return easeOutSine(progress);
            break;
        case EaseType::InOutSine:
            return easeInOutSine(progress);
            break;
        case EaseType::InQuad:
            return easeInQuad(progress);
            break;
        case EaseType::OutQuad:
            return easeOutQuad(progress);
            break;
        case EaseType::InOutQuad:
            return easeInOutQuad(progress);
            break;
        case EaseType::InCubic:
            return easeInCubic(progress);
            break;
        case EaseType::OutCubic:
            return easeOutCubic(progress);
            break;
        case EaseType::InOutCubic:
            return easeInOutCubic(progress);
            break;
        case EaseType::InQuart:
            return easeInQuart(progress);
            break;
        case EaseType::OutQuart:
            return easeOutQuart(progress);
            break;
        case EaseType::InOutQuart:
            return easeInOutQuart(progress);
            break;
        case EaseType::InQuint:
            return easeInQuint(progress);
            break;
        case EaseType::OutQuint:
            return easeOutQuint(progress);
            break;
        case EaseType::InOutQuint:
            return easeInOutQuint(progress);
            break;
        case EaseType::InExpo:
            return easeInExpo(progress);
            break;
        case EaseType::OutExpo:
            return easeOutExpo(progress);
            break;
        case EaseType::InOutExpo:
            return easeInOutExpo(progress);
            break;
        case EaseType::InCirc:
            return easeInCirc(progress);
            break;
        case EaseType::OutCirc:
            return easeOutCirc(progress);
            break;
        case EaseType::InOutCirc:
            return easeInOutCirc(progress);
            break;
        case EaseType::InBack:
            return easeInBack(progress);
            break;
        case EaseType::OutBack:
            return easeOutBack(progress);
            break;
        case EaseType::InOutBack:
            return easeInOutBack(progress);
            break;
        case EaseType::InElastic:
            return easeInElastic(progress);
            break;
        case EaseType::OutElastic:
            return easeOutElastic(progress);
            break;
        case EaseType::InOutElastic:
            return easeInOutElastic(progress);
            break;
        case EaseType::InBounce:
            return easeInBounce(progress);
            break;
        case EaseType::OutBounce:
            return easeOutBounce(progress);
            break;
        case EaseType::InOutBounce:
            return easeInOutBounce(progress);
            break;
        default:
            return progress;
            break;
        }
    }
}