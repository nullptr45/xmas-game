#include "entity.h"

bool colliding(Entity *a, Entity *b)
{
    float c = a->radius + b->radius;
    float x = a->pos.x - b->pos.x;
    float y = a->pos.y - b->pos.y;

    return c * c > x * x + y * y;
}
