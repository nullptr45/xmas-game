#pragma once

#include "entity.h"

#include <raylib.h>
#include <stdbool.h>

typedef enum {
    ENEMY_TYPE_NONE,
    ENEMY_TYPE_MELEE,
    ENEMY_TYPE_RANGE,
} EnemyType;

typedef enum {
    ENEMY_RANK_NONE,
    ENEMY_RANK_WEAK,
    ENEMY_RANK_NORMAL,
    ENEMY_RANK_BADASS,
} EnemyRank;

typedef struct {
    Entity entity;
    float health;
    EnemyType type;
} Enemy;

void enemy_init(Enemy *enemy);
void enemy_spawn(Enemy *enemy, Vector2 pos, EnemyType type, EnemyRank rank);
void enemy_update(Enemy *enemy, float delta);
void enemy_render(Enemy *enemy);
void enemy_shutdown(Enemy *enemy);
