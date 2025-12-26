#include "projectile.h"

#include <raymath.h>

void projectile_spawn(Projectile *p, Vector2 position, Vector2 direction, float speed, float damage)
{
    p->entity = (Entity) {
        .pos = position,
        .radius = 4,
        .tint = YELLOW,
        .active = true
    };
    p->speed = speed;
    p->damage = damage;
    p->direction = direction;
    p->lifetime = 5;
}

void projectile_update(Projectile *p, float delta)
{
    if (!p->entity.active) return;

    p->entity.pos = Vector2Add(p->entity.pos, Vector2Scale(p->direction, p->speed * delta));
    p->lifetime -= delta;

    if (p->lifetime <= 0) {
        p->entity.active = false;
    }
}

void projectile_render(Projectile *p)
{
    if (!p->entity.active) return;

    DrawCircleV(
        p->entity.pos,
        p->entity.radius,
        p->entity.tint
    );
}

