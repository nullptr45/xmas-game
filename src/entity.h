#pragma once

#include <raylib.h>
#include <stdbool.h>

typedef struct {
    Vector2 pos;
    Vector2 vel;
    float radius;
    Color tint;
    bool active;
} Entity;

bool colliding(Entity *a, Entity *b);
void resolve_collision(Entity *a, Entity *b);
