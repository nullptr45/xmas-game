#include <stdio.h>
#include <raylib.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "game");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
