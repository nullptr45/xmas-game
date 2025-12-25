#include "game.h"

#include <stdio.h>
#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "game");
    SetTargetFPS(60);
    srand(time(NULL));

    GameData game;
    game_init(&game);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        float delta_time = GetFrameTime();
        game_update(&game, delta_time);
        game_render(&game);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
