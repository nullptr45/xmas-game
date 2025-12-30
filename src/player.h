#pragma once

#include "entity.h"
#include "item.h"

#include <raylib.h>

#define NUM_ITEMS 4

typedef struct {
    Entity entity;

    float health;
    float max_health;
    float shield_health;
    int rounds;
    bool is_reloading;

    float shoot_timer;
    float reload_timer;
    float shield_timer;

    float xp;
    float max_xp;
    int level;

    Item weapon;
    Item shield;

    Item inventory[NUM_ITEMS];
} Player;

void player_init(Player *player, Vector2 position);
void player_update(Player *player, float delta);
void player_render(Player *player);
void player_take_damage(Player *player, float damage);
void player_take_knockback(Player *player, Vector2 dir, float knockback);
void player_gain_xp(Player *player, float xp);
