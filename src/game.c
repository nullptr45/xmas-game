#include "game.h"

void game_init(GameData *game)
{
    player_init(&game->player, (Vector2){640, 360});

    for (int i = 0; i < MAX_ENEMIES; ++i) {
        enemy_init(&game->enemies[i]);
    }
}

void game_update(GameData *game, float delta)
{
    player_update(&game->player, delta);

    for (int i = 0; i < MAX_ENEMIES; ++i) {
        enemy_update(&game->enemies[i], delta);
    }
}

void game_render(GameData *game)
{
    player_render(&game->player);

    for (int i = 0; i < MAX_ENEMIES; ++i) {
        enemy_render(&game->enemies[i]);
    }
}

