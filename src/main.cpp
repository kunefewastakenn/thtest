//
// Created by pixeloyuncu on 6/10/2026.
//

#include <iostream>
#include <raylib.h>
#include <algorithm>
#include <cstring>
#include <thread>

#include <supertext.h>

std::string initText = "Initializing";
bool loaded = false;

// handle loading string
void loadingScreen() {
    while (rand()%100<90) {
        if (std::count(initText.begin(), initText.end(), '.') == 3) {
            initText = "Initializing.";
        } else {
            initText += ".";
        }
        std::cout << initText << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    loaded = true;
}

int main() {
    InitWindow(800, 450, "Touhou: Through the Bamboo Forest");
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    std::thread loadingThread(loadingScreen); // thread for loading text

    while (!loaded) {
        BeginDrawing();
        ClearBackground(BLACK);

        int fontSize = 24;
        int textWidth = MeasureText(initText.c_str(), fontSize);

        DrawText(initText.c_str(), (GetScreenWidth() / 2) - (textWidth / 2), 225, fontSize, LIGHTGRAY);
        EndDrawing();
    }

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        int textWidth = MeasureText("VICTORY :D", 35);
        DrawText("VICTORY :D", (GetScreenWidth() / 2) - (textWidth / 2), 225, 35, LIGHTGRAY);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
