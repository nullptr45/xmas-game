#pragma once

#include "enemy.h"
#include "player.h"
#include "projectile.h"

#define MAX_ENEMIES 256
#define MAX_PROJECTILES 256

typedef struct {
    Player player;
    Enemy enemies[MAX_ENEMIES];
    Projectile projectiles[MAX_PROJECTILES];
    Camera2D camera;
} GameData;

void game_init(GameData *game);
void game_update(GameData *game, float delta);
void game_render(GameData *game);
