#pragma once

#include "game/components/render/material.h"
#include "game/components/render/text.h"
#include "game/components/render/transform.h"
#include "system/asset_manager.h"
#include "system/intent_storage.h"

namespace Game::Render
{
    struct GraphData
    {
        Math::Point glyph_top_left, glyph_top_right, glyph_bottom_left, glyph_bottom_right;
        float u0, u1, v0, v1;
    };

    template<typename T>
    void draw_text([[maybe_unused]] T &syscall, System::ECS::Query<Text, Material, Transform> &query)
    {
        for (auto &[id, comps]: query)
        {
            std::vector<GraphData> graph_data;
            const auto &material = comps.get<Material>();
            if (!material.visible)
                continue;

            const auto &[font, text, color, layer, order, align] = comps.get<Text>();
            const auto &tra = comps.get<Transform>();
            const auto scale_point(Math::Point(tra.scaleX, tra.scaleY, 1));

            const auto glyphs_data = font->info.info.as_font.data;
            const auto glyphs_count = font->info.info.as_font.count;

            // in local space, the "pen" starts at (0,0,0).
            auto pen = Math::Point(0, 0, 0);

            for (const char c: text)
            {
                int i = 0;
                while (i < static_cast<int>(glyphs_count))
                {
                    if (glyphs_data[i].character == c)
                    {
                        break;
                    }
                    i++;
                }

                if (i == static_cast<int>(glyphs_count))
                {
                    continue;
                } // cannot render, no glyph data
                const auto glyph = &glyphs_data[i];
                const auto u0 = glyph->u0;
                const auto v0 = glyph->v0;
                const auto u1 = glyph->u1;
                const auto v1 = glyph->v1;
                const auto width = glyph->width;
                const auto height = glyph->height;
                const auto bearing_x = glyph->bearing_x;
                const auto bearing_y = glyph->bearing_y;
                const auto advance = glyph->advance;

                const auto glyph_left = pen.x + static_cast<float>(bearing_x);
                const auto glyph_bottom = pen.y - static_cast<float>(height) + static_cast<float>(bearing_y);
                const auto glyph_right = glyph_left + static_cast<float>(width);
                const auto glyph_top = glyph_bottom + static_cast<float>(height);

                const auto glyph_bottom_left = Math::Point{.x = glyph_left, .y = glyph_bottom, .z = 0};
                const auto glyph_bottom_right = Math::Point{.x = glyph_right, .y = glyph_bottom, .z = 0};
                const auto glyph_top_left = Math::Point{.x = glyph_left, .y = glyph_top, .z = 0};
                const auto glyph_top_right = Math::Point{.x = glyph_right, .y = glyph_top, .z = 0};

                graph_data.emplace_back(
                        glyph_top_left, glyph_top_right, glyph_bottom_left, glyph_bottom_right, u0, u1, v0, v1);

                pen.x += advance;
            }

            Transform new_transform = tra;

            if (align == TextAlign::Center)
                new_transform.position.x -= pen.x / 2; // Should + with center text font size
            if (align == TextAlign::Right)
                new_transform.position.x -= pen.x;

            for (const auto [glyph_top_left, glyph_top_right, glyph_bottom_left, glyph_bottom_right, u0, u1, v0, v1]:
                 graph_data)
            {
                auto &intent = System::Render::IntentStorage::allocate_packed();
                intent.kind = System::Render::DrawKind::KIND_SPRITE;

                Helpers::fill_common(intent, material, new_transform, static_cast<uint8_t>(layer));

                intent.common.sp = font;
                intent.common.info.sp_id = ASSET_INDEX(font->id);

                intent.special.sprite = System::Render::SpriteDrawDesc{
                        .points =
                                {glyph_top_left * scale_point,
                                 glyph_top_right * scale_point,
                                 glyph_bottom_right * scale_point,
                                 glyph_bottom_left * scale_point},
                        .color = color,
                        .u0 = u0,
                        .v0 = v0,
                        .u1 = u1,
                        .v1 = v1,
                        .flipX = false,
                        .flipY = false};
            }
        }
    }
} // namespace Game::Render
