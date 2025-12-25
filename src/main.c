#include "player.h"
#include "enemy.h"

#include <stdio.h>
#include <raylib.h>
#include <raymath.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "game");
    SetTargetFPS(60);

    Player player;
    player_create(&player, (Vector2){WINDOW_WIDTH * 0.5, WINDOW_HEIGHT * 0.5});

    Enemy enemy;
    enemy_init(&enemy, (Vector2){WINDOW_WIDTH *0.5, WINDOW_HEIGHT * 0.5}, ENEMY_TYPE_MELEE);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        float delta_time = GetFrameTime();
        player_update(&player, delta_time);
        enemy_update(&enemy, delta_time);

        player_render(&player);
        enemy_render(&enemy);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
