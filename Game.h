//
// Created by Jasdeep saran on 2023-07-19.
//
#pragma once
#include "Paddle.h"
#include "Ball.h"

class Game{
public:
    bool Init();
    void Shutdown();
    void GameLoop();



private:
    void HandleEvents();
    void Update();
    void Draw();


    bool isRunning=true;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    class Paddle* leftPaddle;
    class Paddle* rightPaddle;
    class Ball* ball;
};



