#include "player.h"

#include <raymath.h>

#define PLAYER_ACC 5.0

void player_create(Player *player, Vector2 position)
{
    player->vel = Vector2Zero();
    player->acc = Vector2Zero();
    player->pos = position;
}

void player_update(Player *player)
{
    if (IsKeyDown(KEY_W)) {
        player->acc.y -= 5.0;
    }

    if (IsKeyDown(KEY_S)) {
        player->acc.y += 5.0;
    }

    if (IsKeyDown(KEY_A)) {
        player->acc.x -= 5.0;
    }

    if (IsKeyDown(KEY_D)) {
        player->acc.x += 5.0;
    }

    player->vel = player->acc;
    player->pos = player->vel;
}

void player_render(Player *player)
{
    DrawRectangle(player->pos.x, player->pos.y, 50, 50, RED);
}

void player_destroy(Player *player)
{
}

