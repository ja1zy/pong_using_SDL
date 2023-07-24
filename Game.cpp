//
// Created by Jasdeep saran on 2023-07-19.
//

#include "Game.h"
bool Game::Init() {

    if(SDL_Init(SDL_INIT_VIDEO) !=0 ){
        return false;
    }
    window = SDL_CreateWindow("Pong_tutorial", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1270,800, 0);
    //display error if window not displayed
    if(!window){
        return false;
    }


    renderer= SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!renderer){
        return false;
    }
    //initialzie the two paddles
    leftPaddle = new Paddle(0);
    rightPaddle = new Paddle(1);


    return true;
}
void Game::GameLoop() {
    while(isRunning){
        HandleEvents();
        Update();
        Draw();
    }
}
void Game:: HandleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type==SDL_QUIT){
            isRunning  = false;
        }
    }

    const Uint8* keystates = SDL_GetKeyboardState(NULL);

    if(keystates[SDL_SCANCODE_ESCAPE]){
        isRunning = false;
    }


    // left paddle movemments
    //event is polled every frame;
    //this line of code guarantees that movement is stopped
    //when we do nothing!
    leftPaddle->setDir(0);
        if(keystates[SDL_SCANCODE_W]){
            leftPaddle->setDir(-1);
        }
        if(keystates[SDL_SCANCODE_S]){
            leftPaddle->setDir(1);
        }

    rightPaddle->setDir(0);
    if(keystates[SDL_SCANCODE_UP]){
        rightPaddle->setDir(-1);
    }
    if(keystates[SDL_SCANCODE_DOWN]){
        rightPaddle->setDir(1);
    }




}

void Game::Update() {
  //updates paddles current position!
    leftPaddle->Update();
    rightPaddle->Update();
}
void Game::Draw() {
    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
    SDL_RenderClear(renderer);

    //draw paddles
    SDL_SetRenderDrawColor(renderer,255,255,255,255);

    SDL_RenderFillRect(renderer, leftPaddle-> GetRect());
    SDL_RenderFillRect(renderer, rightPaddle-> GetRect());



    SDL_RenderPresent(renderer);
}
void Game::Shutdown(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}