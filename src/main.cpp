//
// Created by pixeloyuncu on 6/10/2026.
//

#include <iostream>
#include <raylib.h>
#include <chrono>
//#include <supertext.h>
#include <algorithm>
#include <cstring>
#include <thread>

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
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 450, "Touhou: Through the Bamboo Forest");

    std::thread loadingThread(loadingScreen); // thread for loading text

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText(TextFormat("%i FPS", GetFPS()), 10, 10, 16, LIGHTGRAY);

        if (!loaded) {
            int fontSize = 24;
            int textWidth = MeasureText(initText.c_str(), fontSize);
            DrawText(initText.c_str(), (GetScreenWidth() / 2) - (textWidth / 2), 225, fontSize, WHITE);

            DrawRectanglePro({GetScreenWidth()/2.0f, GetScreenHeight()/2.0f+100, 40, 40}, {20, 20},
                (clock()/4) % 360, WHITE);
        } else {
            int textWidth = MeasureText("VICTORY :D", 35);
            DrawText("VICTORY :D", (GetScreenWidth() / 2) - (textWidth / 2), 225, 35, YELLOW);
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
