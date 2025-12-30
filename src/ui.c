#include "ui.h"

#include <raylib.h>
#include <stdio.h>

static void draw_bar(Vector2 pos, Vector2 size, float value, float max_value, Color fill, Color back, Color frame)
{
    float t = (max_value > 0.0f) ? value / max_value : 0.0f;
    if (t < 0.0f) t = 0.0f;
    if (t > 1.0f) t = 1.0f;

    DrawRectangleV(pos, size, back);
    DrawRectangle(pos.x, pos.y, size.x * t, size.y, fill);
    DrawRectangleLinesEx((Rectangle){pos.x, pos.y, size.x, size.y}, 2.0f, frame);
}

void ui_draw(const Player *player)
{
    const int margin = 20;
    const int bar_width = 220;
    const int xp_bar_width = bar_width * 1.5;
    const int bar_height = 18;
    const int spacing = 6;

    Vector2 base = {
        margin,
        GetScreenHeight() - margin - (bar_height * 2 + spacing)
    };

    // Shield
    draw_bar(
        base,
        (Vector2){bar_width, bar_height},
        player->shield_health,
        player->shield.shield.capacity,
        (Color){80, 160, 255, 255},
        (Color){20, 20, 30, 255},
        BLUE
    );

    DrawText(
        TextFormat("%.0f", player->shield_health),
        base.x + 6,
        base.y + 4,
        12,
        LIGHTGRAY
    );

    // Health
    Vector2 health_pos = {
        base.x,
        base.y + bar_height + spacing
    };

    draw_bar(
        health_pos,
        (Vector2){bar_width, bar_height},
        player->health,
        player->max_health,
        (Color){200, 40, 40, 255},
        (Color){30, 10, 10, 255},
        RED
    );

    DrawText(
        TextFormat("%.0f", player->health),
        health_pos.x + 6,
        health_pos.y + 4,
        12,
        LIGHTGRAY
    );

    // XP
    Vector2 xp_pos = {
        GetScreenWidth() * 0.5f - xp_bar_width * 0.5f,
        base.y + bar_height + spacing
    };

    draw_bar(
        xp_pos,
        (Vector2){xp_bar_width, bar_height},
        player->xp,
        player->max_xp,
        (Color){80, 160, 255, 255},
        (Color){20, 20, 30, 255},
        BLUE
    );

    DrawText(
        TextFormat("Level %d", player->level),
        xp_pos.x + 6,
        xp_pos.y + 4,
        12,
        LIGHTGRAY
    );

    // Ammo
    char ammo_text[64];
    snprintf(ammo_text, sizeof(ammo_text), "%d / %d", player->rounds, player->weapon.weapon.mag_size);

    int font_size = 28;
    int text_width = MeasureText(ammo_text, font_size);

    Vector2 ammo_pos = {
        GetScreenWidth() - margin - text_width,
        GetScreenHeight() - margin - font_size
    };

    DrawText(ammo_text, ammo_pos.x, ammo_pos.y, font_size, GOLD);
}

