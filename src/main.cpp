#include <raylib.h>

int main() {
    InitWindow(800, 600, "MAL");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RED);
        DrawText("67 ", 300, 280, 20, BLUE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}