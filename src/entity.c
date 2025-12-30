#include "entity.h"

#include <raymath.h>

bool colliding(Entity *a, Entity *b)
{
    float c = a->radius + b->radius;
    float x = a->pos.x - b->pos.x;
    float y = a->pos.y - b->pos.y;

    return c * c > x * x + y * y;
}

void resolve_collision(Entity *a, Entity *b)
{
    Vector2 delta = Vector2Subtract(b->pos, a->pos);
    float dist = Vector2Length(delta);

    if (dist == 0.0f) return;

    float penetration = (a->radius + b->radius) - dist;
    if (penetration <= 0.0f) return;

    Vector2 normal = Vector2Scale(delta, 1.0f / dist);

    Vector2 correction = Vector2Scale(normal, penetration * 0.5f);

    a->pos = Vector2Subtract(a->pos, correction);
    b->pos = Vector2Add(b->pos, correction);
}

