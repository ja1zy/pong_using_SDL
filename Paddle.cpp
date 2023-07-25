//
// Created by Jasdeep saran on 2023-07-22.
//

#include "Paddle.h"
Paddle ::Paddle(int i){
    id =i;
    speed = 20.f;
    if(id==0){
        pos.x=0;
        pos.y= SCREEN_HEIGHT/2-height/2;
    }else if(id==1){
        pos.x= SCREEN_WIDTH-width;
        pos.y= SCREEN_HEIGHT/2-height/2;
    }


    rect.x= (int)pos.x;
    rect.y=(int)pos.y;
    rect.w=width;
    rect.h=height;

};

//drawing will happen where the renderer is
void Paddle::Update(){


    pos.y=pos.y+ speed*dir;
    if(pos.y<0){
        pos.y=0;
    }
    //y is the top position of paddle.
    //height is the height of the paddle
    if(pos.y+height>SCREEN_HEIGHT){
        pos.y=SCREEN_HEIGHT-height;
    }
    //allows the paddles to move
    rect.y=pos.y;
}
void Paddle::setDir(int d){
    dir=d;
}

SDL_Rect* Paddle::GetRect() {
    return &rect;
}



