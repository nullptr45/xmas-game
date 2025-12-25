#pragma once

#include <raylib.h>

typedef enum {
    ENEMY_TYPE_MELEE,
    ENEMY_TYPE_RANGE,
} EnemyType;

typedef struct {
    Vector2 position;
    Color color;
    float health;
    EnemyType type;
} Enemy;

void enemy_init(Enemy *enemy, Vector2 position, EnemyType type);
void enemy_update(Enemy *enemy, float delta);
void enemy_render(Enemy *enemy);
void enemy_shutdown(Enemy *enemy);
