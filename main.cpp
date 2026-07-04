#include "raylib.h"
#include "raymath.h"
#include <cmath>
#include <iostream>


int main(){

    const int screenWidth = 800;
    const int screenHeight = 450;
    float margin = 40.0f;
    int letters = 0;
    int enemyletters = 0;


    InitWindow(screenWidth, screenHeight, "Pong");

    Rectangle paddle = {40.0f, 300.0f, 20.0f, 100.0f};
    Rectangle paddle2 = {(float)screenWidth - margin, (float)screenHeight / 2, 20.0f, 100.0f};
    Vector2 ballposition = {screenWidth/2, screenHeight/2};
    Vector2 ballspeed = {5.0f, 1.0f};

    float size = 40.0f;

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
        ballposition.x += ballspeed.x;
        ballposition.y += ballspeed.y;
        
        if (CheckCollisionCircleRec(ballposition, 10, paddle))
        {
            ballspeed.x = std::fabs(ballspeed.x) * 1.05f;
            ballposition.x = paddle.x + paddle.width + 10;
        }
        else if (CheckCollisionCircleRec(ballposition, 10, paddle2))
        {
            ballspeed.x = -std::fabs(ballspeed.x) * 1.05f;
            ballposition.x = paddle2.x - 10;               
        }
        if (ballposition.y <= 10)
        {
            ballposition.y = 10;
            ballspeed.y *= -1.0f;
        }
            
        else if (ballposition.y >= screenHeight - 10)
        {
            ballposition.y = screenHeight - 10;
            ballspeed.y *= -1.0f;
        }
        if (paddle.y >= screenHeight - 110)
        {
            paddle.y = screenHeight - 110;
        }
        else if (paddle2.y >= screenHeight - 110) // SO PRO PADDLEE NAO FICA FUGINDO DA TELA
        {
            paddle2.y = screenHeight - 110;
        }

        if (ballposition.x >= screenWidth + 30)
        {
            letters += 1;
            ballspeed.x = 5.0f;
            ballspeed.y = 1.0f;
            ballposition.x = screenWidth / 2;
            ballposition.y = screenHeight / 2;
        } else if (ballposition.x <= paddle.x - 20)
        {
            letters += 1;
            ballspeed.x = 5.0f;
            ballspeed.y = 1.0f;
            ballposition.x = screenWidth / 2;
            ballposition.y = screenHeight / 2;
        }


        if (paddle2.y + 50 < ballposition.y)
        {
            paddle2.y += 4;
        }
        else if (paddle2.y - 50 < ballposition.y)
        {
            paddle2.y -= 4;
        }
        
        
        
        

        
        
        
        

        
        
        
        BeginDrawing();
            ClearBackground(BLACK);

            DrawRectangleRec(paddle, WHITE);
            DrawRectangleRec(paddle2, WHITE);
            DrawCircleV(ballposition, 10, WHITE);
            DrawText(TextFormat("%i", letters), screenWidth/4, 30, 20, WHITE);
            DrawText(TextFormat("%i", enemyletters), (screenWidth / 4) * 3, 30, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    

    return 0;
}