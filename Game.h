//
// Created by Jasdeep saran on 2023-07-19.
//
#pragma once
#include "Paddle.h"
#include "Ball.h"
#include "Score.h"
#include "Utils.h"
#include "Menu.h"

class Game{
public:
    bool Init();
    void Shutdown();
    void GameLoop();
    void Reset();
    bool pause=false;
    bool pauseBall=false;


private:
    void HandleEvents();
    void Update();
    void Draw();


    bool isRunning=true;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Surface* surface= nullptr;
    SDL_Texture* texture= nullptr;
    TTF_Font* font;


    class Paddle* leftPaddle;
    class Paddle* rightPaddle;
    class Ball* ball;
    class Score* score1;
    class Score* score2;
    class Menu* menu;

};



