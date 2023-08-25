//
// Created by Jasdeep saran on 2023-07-23.
//

#include "Ball.h"
//
// Created by Jasdeep saran on 2023-07-22.
//
Ball::Ball(){

    speed = 3.f;
    //initial position
    pos.x=SCREEN_WIDTH/2-size/2;
    pos.y=SCREEN_HEIGHT/2-size/2;
    vel.x= VELOCITY[rand()%2];
    vel.y=-VELOCITY[(rand()%2)];


    rect.x= (int)pos.x;
    rect.y=(int)pos.y;
    rect.w=size;
    rect.h=size;

};
int Ball::GetPosX() {
    return pos.x;
}
int Ball:: GetPosY(){
    return pos.y;
}


void Ball::SetVel(float x, float y){
    vel.x=x;
    vel.y=y;
}
void Ball::DetectCollision(bool val){
    collision = val;
    if(speed<=10){
        speed+=.25;
    }
}
void Ball::Reset() {
    vel.x= VELOCITY[rand()%2];
    vel.y=-VELOCITY[(rand()%2)];
    pos.x=SCREEN_WIDTH/2-size/2;
    pos.y=SCREEN_HEIGHT/2-size/2;
    rect.x= (int)pos.x;
    rect.y=(int)pos.y;
}


void Ball::Update(){
    pos.x = (int)pos.x+speed* vel.x;
    pos.y = (int)pos.y+speed*vel.y;

    //use a boolean that checks posx of paddle and ball. to confirm!

    /* collision stuff here! */
    if(collision) {
        if (pos.x <= size) {
            Ball::SetVel(1, vel.y);
            pos.x = size;
        } else if (pos.x >= SCREEN_WIDTH-size*2) {
            Ball::SetVel(-1, vel.y);
            pos.x = SCREEN_WIDTH-size*2;
        }
    }

    //Upper walls. this does not change!
    if(pos.y<=0){
        Ball::SetVel(vel.x,1);
        pos.y=0;
    }else if (pos.y>=SCREEN_HEIGHT-size){
        Ball::SetVel(vel.x,-1);
        pos.y=SCREEN_HEIGHT-size;
    }

    rect.x=pos.x;
    rect.y=pos.y;
    collision=false;
}


SDL_Rect* Ball::GetRect(){
    return &rect;
}
//draw here maybe?


