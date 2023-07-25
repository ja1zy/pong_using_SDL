//
// Created by Jasdeep saran on 2023-07-22.
//


#ifndef PONG_TUTORIAL_PADDLE_H
#define PONG_TUTORIAL_PADDLE_H
#include "Utils.h"

class Paddle {
public:
    Paddle(int i);
    void Draw();
    void Update();
    //have to get a getter
    SDL_Rect* GetRect();

    void setDir(int d);


private:
    int id;
    int dir=0;
    int width=20;
    int height=140;
    Vec2 pos;

    float speed;
    SDL_Rect rect;





};


#endif //PONG_TUTORIAL_PADDLE_H
