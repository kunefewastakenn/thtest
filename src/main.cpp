//
// Created by pixeloyuncu on 6/10/2026.
//

#include <iostream>
#include <raylib.h>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <thread>
#include <tweeny.h>

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
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    loaded = true;
}

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1280, 960, "Touhou: The Final Showdown");

    Texture2D ardaImg = LoadTexture("resources/images/arda.png");
    Texture2D loadingImg = LoadTexture("resources/images/loading.png");

    Font cirnoTtf = LoadFontEx("resources/fonts/Cirno.ttf", 128, 0, 250);

    std::thread loadingThread(loadingScreen); // thread for loading text

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawTexturePro(ardaImg, {0, 0, 548, 426}, {0, 0, 2048, 2048}, {1024,1024}, (clock()/4)%360, WHITE);
        DrawText(TextFormat("%i FPS", GetFPS()), 10, 10, 16, LIGHTGRAY);

        if (!loaded) {
            int fontSize = 24;
            int textWidth = MeasureText(initText.c_str(), fontSize);
            DrawText(initText.c_str(), (GetScreenWidth() / 2) - (textWidth / 2), (GetScreenHeight()/2), fontSize, WHITE);
            DrawTexturePro(loadingImg, {0, 0, 32, 32}, {GetScreenWidth()/2.0f, GetScreenHeight()/2.0f+100, 40, 40}, {20,20}, (clock()/4)%360, WHITE);
        } else {
            Vector2 textWH = MeasureTextEx(cirnoTtf, "VICTORY :D", 128, 0);
            DrawTextEx(cirnoTtf, "VICTORY :D",
                {(GetScreenWidth() / 2.0f) - (textWH.x / 2.0f), (GetScreenHeight()/2.0f) - textWH.y / 2.0f},
                128, 0, YELLOW);
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
