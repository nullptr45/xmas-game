#include "player.h"
#include "entity.h"
#include "item.h"

#include <math.h>
#include <raylib.h>
#include <raymath.h>

void player_init(Player *player, Vector2 position)
{
    player->entity = (Entity) {
        .pos = position,
        .radius = 20,
        .tint = BLUE,
        .active = true
    };

    player->health = 100;

    player->equipped_shield = item_generate_shield(ITEM_RARITY_COMMON);
    player->shield = player->equipped_shield.shield.capacity;

    player->equipped_weapon = item_generate_weapon(ITEM_RARITY_COMMON);
    player->rounds = player->equipped_weapon.weapon.mag_size;

    for (int i = 0; i < NUM_ITEMS; i++) {
        player->inventory[i] = (Item){ .type = ITEM_TYPE_NONE };
    }

    player->inventory[0] = player->equipped_weapon;

    player->shoot_timer = 0;
    player->reload_timer = 0;
}

void player_update(Player *player, float delta)
{
    Vector2 move = Vector2Zero();
    const float move_speed = 200;

    if (IsKeyDown(KEY_W)) {
        move.y = -1;
    }

    if (IsKeyDown(KEY_S)) {
        move.y = 1;
    }

    if (IsKeyDown(KEY_A)) {
        move.x = -1;
    }

    if (IsKeyDown(KEY_D)) {
        move.x = 1;
    }

    if (move.x != 0 || move.y != 0) {
        move = Vector2Normalize(move);
        move = Vector2Scale(move, delta * move_speed);
    }

    player->entity.pos = Vector2Add(player->entity.pos, move);

    if (player->shoot_timer > 0) {
        player->shoot_timer -= delta;
    }

    if (player->reload_timer > 0) {
        player->reload_timer -= delta;
    } else {
        player->rounds = player->equipped_weapon.weapon.mag_size;
    }
}

void player_render(Player *player)
{
    DrawCircleV(player->entity.pos, player->entity.radius, player->entity.tint);
}

void player_destroy(Player *player)
{
}

