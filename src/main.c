#include "player.h"

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
    player_create(&player, (Vector2){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        player_update(&player);
        player_render(&player);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
