#include "enemy.h"

void enemy_init(Enemy *enemy, Vector2 position, EnemyType type)
{
    enemy->position = position;
    enemy->type = type;
    enemy->color = RED;
}

void enemy_update(Enemy *enemy, float delts)
{
    // TODO: enemy AI
}

void enemy_render(Enemy *enemy)
{
    DrawRectangle(enemy->position.x, enemy->position.y, 50, 50, enemy->color);
}

void enemy_shutdown(Enemy *enemy)
{
}

