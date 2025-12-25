#include "player.h"

#include <raymath.h>

void player_create(Player *player, Vector2 position)
{
    player->pos = position;
}

void player_update(Player *player, float delta)
{
    Vector2 move = Vector2Zero();
    const float move_speed = 200;

    if (IsKeyDown(KEY_W)) {
        move.y = -1;
    }

    if (IsKeyDown(KEY_S)) {
        move.y = 1;
    }

    if (IsKeyDown(KEY_A)) {
        move.x = -1;
    }

    if (IsKeyDown(KEY_D)) {
        move.x = 1;
    }

    if (move.x != 0 || move.y != 0) {
        move = Vector2Normalize(move);
        move = Vector2Scale(move, delta * move_speed);
    }

    player->pos = Vector2Add(player->pos, move);
}

void player_render(Player *player)
{
    DrawRectangle(player->pos.x, player->pos.y, 50, 50, BLUE);
}

void player_destroy(Player *player)
{
}

