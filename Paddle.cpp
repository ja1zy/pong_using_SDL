//
// Created by Jasdeep saran on 2023-07-22.
//

#include "Paddle.h"
Paddle ::Paddle(int i){
    id =i;
    speed = 20.f;
    if(id==0){
        x=0;
        y= SCREEN_HEIGHT/2-height/2;
    }else if(id==1){
        x= SCREEN_WIDTH-width;
        y= SCREEN_HEIGHT/2-height/2;
    }


    rect.x= (int)x;
    rect.y=(int)y;
    rect.w=width;
    rect.h=height;

};

//drawing will happen where the renderer is
void Paddle::Update(){


    y=y+ speed*dir;
    if(y<0){
        y=0;
    }
    //y is the top position of paddle.
    //height is the height of the paddle
    if(y+height>SCREEN_HEIGHT){
        y=SCREEN_HEIGHT-height;
    }




    rect.y=y;
}
void Paddle::setDir(int d){
    dir=d;
}

SDL_Rect* Paddle::GetRect() {
    return &rect;
}



