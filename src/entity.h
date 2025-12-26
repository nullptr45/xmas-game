#pragma once

#include <raylib.h>
#include <stdbool.h>

typedef struct {
    Vector2 pos;

    float radius;
    // Rectangle sprite_src;
    Color tint;

    bool active;
} Entity;

bool colliding(Entity *a, Entity *b);
