//
// Created by Jasdeep saran on 2023-07-19.
//

#include "Game.h"
#include <iostream>
bool Game::Init() {

    if(SDL_Init(SDL_INIT_VIDEO) !=0 ){
        return false;
    }
    if(TTF_Init()<0){

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


    font = TTF_OpenFont("Roboto-Italic.ttf", 50);
    if(font==NULL){
        std::cout<<"Font not loaded correctly";
    }


    /*
     * this is to built the text in the pong tutorial!
    surface = TTF_RenderText_Solid(font, "0", {0xFF, 0xFF, 0xFF, 0xFF});
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    */
    //initialzie the two paddles
    leftPaddle =  new Paddle(0);
    rightPaddle =  new Paddle(1);

    score1= new Score(renderer,font, SCREEN_WIDTH/ 4, 20);
    score2 = new Score(renderer,font, 3*SCREEN_WIDTH / 4, 20);
    menu = new Menu(renderer, font, SCREEN_WIDTH/4,SCREEN_HEIGHT/2);

    ball = new Ball;
    return true;
}
void Game::GameLoop() {
    while(isRunning){
        HandleEvents();
        //if pause is true, stop updating and drawing
        if(!pause){
            Update();
        }
        Draw();
    }
}
void Game:: HandleEvents(){
    pauseBall=false;
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

    if(keystates[SDL_SCANCODE_P]){
        pause =true;
        return;
    }

    if (keystates[SDL_SCANCODE_G]){
        pause=false;
        pauseBall=true;
        return;
    }

    if(pause){
        return;
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
      score1->Update();
    }else{
       score2->Update();
    }

    leftPaddle = new Paddle(0);
    rightPaddle = new Paddle(1);

    ball = new Ball;
}

void Game::Update() {
  //updates paddles current position!
    leftPaddle->Update();
    rightPaddle->Update();
    if(!pauseBall){
        ball->Update();
    }
    //score update too!

}
void Game::Draw() {
    //THIS CLEARS THE SCREEN FOR US, SO WE DON'T SEE THE PAST STUFF
    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
    SDL_RenderClear(renderer);

    //draw white paddles
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderFillRect(renderer, leftPaddle-> GetRect());
    SDL_RenderFillRect(renderer, rightPaddle-> GetRect());



    //draw scoreboard
    SDL_RenderCopy(renderer, score1->texture, nullptr, score1->getRect());
    SDL_RenderCopy(renderer, score2->texture, nullptr, score2->getRect());


    //draw ball
    SDL_SetRenderDrawColor(renderer,40, 40, 255, 255);
    SDL_RenderFillRect(renderer, ball-> GetRect());


    if(pause)
        SDL_RenderCopy(renderer, menu->texture, nullptr, menu->getRect());


    //RENDER CURRENT STUFF,like the present!
    SDL_RenderPresent(renderer);
}
void Game::Shutdown(){
    //clean up
    SDL_DestroyRenderer(renderer);
    score1->destroy();
    score2->destroy();
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    SDL_Quit();
    TTF_Quit();

}