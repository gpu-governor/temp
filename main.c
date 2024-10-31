#include "raylib.h"
#include <stdio.h>

const int width = 800;
const int height = 600;
#define BALL_COUNT 16

typedef struct {
    int x;
    int y;
    Texture2D texture;
    float scale;
    char *file_path;
} Asset;

void init();
void quit(Asset balls[], int count);
Asset load_asset(const char *file_path, int x, int y, float scale);
void render_asset(Asset new_asset);

int main() {
    init();
    
    Asset table = load_asset("Assets/table.png", 0, 0, 0.13f);
    Asset cue = load_asset("Assets/cue.png", 150, 150, 0.2f);
    Asset triangle = load_asset("Assets/triangle.png", 400, 150, 0.2f);
    
    // Load all ball assets
    Asset balls[BALL_COUNT];
    char filepath[32];
    for (int i = 0; i < BALL_COUNT; i++) {
        sprintf(filepath, "Assets/ball_%d.png", i + 1);
        balls[i] = load_asset(filepath, 0, 0, 1.0f);
    }
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        render_asset(table);
        render_asset(cue);
        render_asset(triangle);
        
        // Render all balls
        for (int i = 0; i < BALL_COUNT; i++) {
            render_asset(balls[i]);
        }
        
        EndDrawing();
    }

    // Unload textures and close window
    UnloadTexture(table.texture);
    UnloadTexture(cue.texture);
    UnloadTexture(triangle.texture);
    quit(balls, BALL_COUNT);
    return 0;
}

void init() {
    InitWindow(width, height, "8-ball pool game");
    SetTargetFPS(60);
}

void quit(Asset balls[], int count) {
    for (int i = 0; i < count; i++) {
        UnloadTexture(balls[i].texture);
    }
    CloseWindow();
}

Asset load_asset(const char *file_path, int x, int y, float scale) {
    Asset new_asset;
    new_asset.file_path = (char *)file_path;
    new_asset.x = x;
    new_asset.y = y;
    new_asset.scale = scale;
    new_asset.texture = LoadTexture(file_path);
    return new_asset;
}

void render_asset(Asset new_asset) {
    Rectangle src = {0, 0, new_asset.texture.width, new_asset.texture.height};
    Rectangle dst = {new_asset.x, new_asset.y, new_asset.texture.width * new_asset.scale, new_asset.texture.height * new_asset.scale};
    Vector2 origin = {0, 0};
    float rotation = 0.0f;
    DrawTexturePro(new_asset.texture, src, dst, origin, rotation, WHITE);
}
