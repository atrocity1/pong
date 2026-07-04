#include "raylib.h"

int main(){

    const int screenWidth = 800;
    const int screenHeight = 450;
    float margin = 40.0f;


    InitWindow(screenWidth, screenHeight, "Pong");

    Rectangle paddle = {40.0f, 300.0f, 20.0f, 100.0f};
    Vector2 paddle2 = {(float)screenWidth - margin, (float)screenHeight / 2};
    Vector2 ballposition = {screenWidth/2, screenHeight/2};
    Vector2 ballspeed = {5.0f, 5.0f};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {  
        if (IsKeyDown(KEY_W))
        {
            paddle.y -= 5;
            
        }
        else if (IsKeyDown(KEY_S))
        {
            paddle.y += 5;
        }
        
        if (CheckCollisionCircleRec(ballposition, 10, paddle))
        {
            ballposition.x += ballspeed.x;
        }
        else{
            ballposition.x -= ballspeed.x;
        }


        

        
        
        
        BeginDrawing();
            ClearBackground(BLACK);

            DrawRectangle((float)paddle.x, (float)paddle.y, 10, 90, WHITE);
            DrawRectangle((float)paddle2.x, (float)paddle2.y, 10, 90, WHITE);
            DrawCircleV(ballposition, 10, WHITE);

        EndDrawing();
    }

    CloseWindow();
    

    return 0;
}