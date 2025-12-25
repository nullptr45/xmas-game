#include "player.h"
#include "item.h"

#include <raymath.h>

void player_init(Player *player, Vector2 position)
{
    player->pos = position;
    player->health = 100;
    player->equipped_shield = item_generate_shield(ITEM_RARITY_COMMON);
    player->shield = player->equipped_shield.shield.capacity;

    player->equipped_weapon = item_generate_weapon(ITEM_RARITY_COMMON);

    for (int i = 0; i < NUM_ITEMS; i++) {
        player->inventory[i] = (Item){ .type = ITEM_TYPE_NONE };
    }

    player->inventory[0] = player->equipped_weapon;
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

    player->pos = Vector2Add(player->pos, move);
}

void player_render(Player *player)
{
    DrawCircleV(player->pos, 20, BLUE);
    DrawText(TextFormat("Health: %.2f", player->health), 5, 5, 20, BLACK);
    DrawText(TextFormat("Shield: %.2f", player->shield), 5, 25, 20, BLACK);
}

void player_destroy(Player *player)
{
}

