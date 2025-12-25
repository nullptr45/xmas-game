#pragma once

#include <raylib.h>

typedef struct {
    Vector2 pos;
} Player;

void player_create(Player *player, Vector2 position);
void player_update(Player *player, float delta);
void player_render(Player *player);
void player_destroy(Player *player);
