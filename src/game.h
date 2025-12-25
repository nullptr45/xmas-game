#pragma once

#include "enemy.h"
#include "player.h"

#define MAX_ENEMIES 256

typedef struct {
    Player player;
    Enemy enemies[MAX_ENEMIES]; // time constraint so I'm just using a fixed size array
} GameData;

void game_init(GameData *game);
void game_update(GameData *game, float delta);
void game_render(GameData *game);
