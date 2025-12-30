#pragma once

#include "entity.h"
#include "player.h"

#include <raylib.h>
#include <stdbool.h>

#define MAX_ENEMIES 256

typedef enum {
    ENEMY_TYPE_NONE,
    ENEMY_TYPE_MELEE,
    ENEMY_TYPE_RANGE,
} EnemyType;

typedef enum {
    ENEMY_RANK_WEAK,
    ENEMY_RANK_NORMAL,
    ENEMY_RANK_BADASS,
} EnemyRank;

typedef struct {
    Entity entity;

    float max_health;
    float health;
    float speed;

    float damage;
    float attack_cooldown;
    float attack_timer;

    EnemyType type;
    EnemyRank rank;

    bool active;
} Enemy;

void enemy_init(Enemy *enemy, Vector2 position, EnemyRank rank, float scale);
void enemy_update(Enemy *enemy, float delta, Player *player);
void enemy_render(Enemy *enemy);
void enemy_take_damage(Enemy *enemy, Player *player, float damage);
