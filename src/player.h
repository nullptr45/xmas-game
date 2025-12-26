#pragma once

#include "entity.h"
#include "item.h"

#include <raylib.h>

#define NUM_ITEMS 4

typedef struct {
    Entity entity;

    float health;
    float shield;
    int rounds;

    float shoot_timer;
    float reload_timer;

    Item equipped_weapon;
    Item equipped_shield;

    Item inventory[NUM_ITEMS];
} Player;

void player_init(Player *player, Vector2 position);
void player_update(Player *player, float delta);
void player_render(Player *player);
void player_destroy(Player *player);
