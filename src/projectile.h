#pragma once

#include "entity.h"

typedef struct {
    Entity entity;

    Vector2 direction;
    float speed;
    float lifetime;
    float damage;
} Projectile;

void projectile_spawn(Projectile *p, Vector2 position, Vector2 direction, float speed, float damage);
void projectile_update(Projectile *p, float delta);
void projectile_render(Projectile *p);
