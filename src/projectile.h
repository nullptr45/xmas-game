#pragma once

#include "enemy.h"
#include "entity.h"

#define MAX_PROJECTILES 256

typedef struct {
    Entity entity;

    Vector2 direction;
    float speed;
    float lifetime;
    float damage;
} Projectile;

void projectile_spawn(Projectile *p, Vector2 position, Vector2 direction, float speed, float damage);
void projectile_update(Projectile *p, Player *player, float delta, Enemy *enemies);
void projectile_render(Projectile *p);
