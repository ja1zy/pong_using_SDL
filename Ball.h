//
// Created by Jasdeep saran on 2023-07-23.
//

#ifndef PONG_TUTORIAL_BALL_H
#define PONG_TUTORIAL_BALL_H

//
// Created by Jasdeep saran on 2023-07-22.
//

#include "Utils.h"

class Ball {
public:
    Ball();
    void Draw();
    void Update();
    //have to get a getter
    SDL_Rect* GetRect();

    void SetVel(float x, float y);
    void DetectCollision(bool val);
    int GetPosX();
    int GetPosY();

private:
    bool collision=false;
    int size=20;
    Vec2 pos;
    Vec2 vel;
    float speed;
    SDL_Rect rect;





};


#endif //PONG_TUTORIAL_BALL_H






