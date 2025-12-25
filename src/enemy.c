#include "enemy.h"

#include <raymath.h>

void enemy_init(Enemy *enemy)
{
    enemy->pos = Vector2Zero();
    enemy->type = ENEMY_TYPE_NONE;
    enemy->color = RED;
    enemy->active = false;
}

void enemy_update(Enemy *enemy, float delts)
{
    if (!enemy->active) return;
    // TODO: enemy AI
}

void enemy_render(Enemy *enemy)
{
    if (!enemy->active) return;

    DrawCircleV(enemy->pos, 20, RED);
}

void enemy_shutdown(Enemy *enemy)
{
    if (!enemy->active) return;
}

