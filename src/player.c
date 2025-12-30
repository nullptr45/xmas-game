#include "player.h"
#include "entity.h"
#include "item.h"

#include <raylib.h>
#include <raymath.h>

void player_init(Player *player, Vector2 position)
{
    player->entity = (Entity) {
        .pos = position,
        .vel = Vector2Zero(),
        .radius = 20,
        .tint = BLUE,
        .active = true
    };

    player->health = 100;

    player->shield = item_generate_shield(ITEM_RARITY_COMMON);
    player->shield_health = player->shield.shield.capacity;

    player->weapon = item_generate_weapon(ITEM_RARITY_COMMON);
    player->rounds = player->weapon.weapon.mag_size;

    for (int i = 0; i < NUM_ITEMS; i++) {
        player->inventory[i] = (Item){ .type = ITEM_TYPE_NONE };
    }

    player->inventory[0] = player->weapon;

    player->shoot_timer = 0;
    player->reload_timer = 0;
    player->is_reloading = false;
}

void player_update(Player *player, float delta)
{
    static const float acc = 1400;
    static const float friction = 8;
    static const float max_speed = 200;

    Vector2 move = Vector2Zero();

    if (IsKeyDown(KEY_W)) move.y -= 1;
    if (IsKeyDown(KEY_S)) move.y += 1;
    if (IsKeyDown(KEY_A)) move.x -= 1;
    if (IsKeyDown(KEY_D)) move.x += 1;

    if (Vector2LengthSqr(move) > 0.01) {
        move = Vector2Normalize(move);
        player->entity.vel = Vector2Add(player->entity.vel, Vector2Scale(move, acc * delta));
    }

    if (Vector2Length(player->entity.vel) > max_speed) {
        player->entity.vel = Vector2Scale(Vector2Normalize(player->entity.vel), max_speed);
    }

    player->entity.vel = Vector2Lerp(player->entity.vel, Vector2Zero(), friction * delta);
    player->entity.pos = Vector2Add(player->entity.pos, Vector2Scale(player->entity.vel, delta));

    if (player->shoot_timer > 0) {
        player->shoot_timer -= delta;
    }

    if (player->is_reloading) {
        player->reload_timer -= delta;
        if (player->reload_timer <= 0) {
            player->rounds = player->weapon.weapon.mag_size;
            player->is_reloading = false;
        }
    }
}

void player_render(Player *player)
{
    DrawCircleV(player->entity.pos, player->entity.radius, player->entity.tint);
}

void player_destroy(Player *player)
{
}

