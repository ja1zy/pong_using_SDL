//
// Created by Jasdeep saran on 2023-07-23.
//

#include "Ball.h"
//
// Created by Jasdeep saran on 2023-07-22.
//
Ball ::Ball(){

    speed = 2.f;
    //initial position
    pos.x=SCREEN_WIDTH/2-size/2;
    pos.y=SCREEN_HEIGHT/2-size/2;
    vel.x=1;
    vel.y=-1;


    rect.x= (int)pos.x;
    rect.y=(int)pos.y;
    rect.w=size;
    rect.h=size;

};
void Ball::SetVel(float x, float y){
    vel.x=x;
    vel.y=y;
}

void Ball::Update(){
    pos.x = (int)pos.x+speed* vel.x;
    pos.y = (int)pos.y+speed*vel.y;

    if(pos.x<=0){
        Ball::SetVel(1,vel.y);
        pos.x=0;
    }else if(pos.x>=SCREEN_WIDTH-size){
        Ball::SetVel(-1,vel.y);
        pos.x=SCREEN_WIDTH-size;
    }else if(pos.y<=0){
        Ball::SetVel(vel.x,1);
        pos.y=0;
    }else if (pos.y>=SCREEN_HEIGHT-size){
        Ball::SetVel(vel.x,-1);
        pos.y=SCREEN_HEIGHT-size;
    }

    rect.x=pos.x;
    rect.y=pos.y;

}


SDL_Rect* Ball::GetRect(){
    return &rect;
}
//draw here maybe?


