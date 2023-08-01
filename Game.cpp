//
// Created by Jasdeep saran on 2023-07-19.
//

#include "Game.h"
bool Game::Init() {

    if(SDL_Init(SDL_INIT_VIDEO) !=0 ){
        return false;
    }
    window = SDL_CreateWindow("Pong_tutorial", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1270,700, 0);
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

    ball = new Ball;
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
    //set collision off by default


    //detect collision and turn bool true or false accordingly.
    if(ball->GetPosX()<=25 && ball->GetPosX()>=20){
        //check LEFT PADDLE Y
        if(ball->GetPosY()>=leftPaddle->GetPosY()-20&&
            ball->GetPosY()<=leftPaddle->GetPosY()+160){
            ball->DetectCollision(true);
        }
    }else if(ball->GetPosX()>=SCREEN_WIDTH-45&& ball->GetPosX()<=SCREEN_WIDTH-40){
        //check right paddle
        if(ball->GetPosY()>=rightPaddle->GetPosY()-20&&
           ball->GetPosY()<=rightPaddle->GetPosY()+160){
            ball->DetectCollision(true);
        }
    }//end of collision detection!

    if(ball->GetPosX()<=0||ball->GetPosX()>=SCREEN_WIDTH){
        Reset();
    }


}//end of event handler!

void Game::Reset(){

    if(ball->GetPosX()<=0){
        //add one to player 2 !
    }else{
        //add one to player 1!
    }

    leftPaddle = new Paddle(0);
    rightPaddle = new Paddle(1);

    ball = new Ball;
}

void Game::Update() {
  //updates paddles current position!
    leftPaddle->Update();
    rightPaddle->Update();
    ball->Update();
}
void Game::Draw() {
    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
    SDL_RenderClear(renderer);

    //draw paddles
    SDL_SetRenderDrawColor(renderer,255,255,255,255);

    SDL_RenderFillRect(renderer, leftPaddle-> GetRect());
    SDL_RenderFillRect(renderer, rightPaddle-> GetRect());

    SDL_SetRenderDrawColor(renderer,40, 40, 255, 255);
    SDL_RenderFillRect(renderer, ball-> GetRect());


    SDL_RenderPresent(renderer);
}
void Game::Shutdown(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}