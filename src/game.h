#pragma once

#include "enemy.h"
#include "player.h"
#include "projectile.h"

typedef enum {
    GAME_STATE_MENU,
    GAME_STATE_PLAYING,
    GAME_STATE_INVENTORY
} GameState;

typedef struct {
    GameState game_state;
    Player player;
    Enemy enemies[MAX_ENEMIES];
    Projectile projectiles[MAX_PROJECTILES];
    Camera2D camera;
    float duration;
    float spawn_timer;
} GameData;

void game_init(GameData *game);
void game_update(GameData *game, float delta);
void game_render(GameData *game);
