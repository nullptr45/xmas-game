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
    p->lifetime = 2;
}

void projectile_update(Projectile *p, Player *player, float delta, Enemy *enemies)
{
    if (!p->entity.active) return;

    p->entity.pos = Vector2Add(p->entity.pos, Vector2Scale(p->direction, p->speed * delta));

    for (int i = 0; i < MAX_ENEMIES; ++i) {
        if (!enemies[i].entity.active) break;

        if (colliding(&p->entity, &enemies[i].entity)) {
            enemy_take_damage(&enemies[i], player, p->damage);
            p->entity.active = false;
            return;
        }
    }

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

