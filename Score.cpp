//
// Created by Jasdeep saran on 2023-08-03.
//

#include "Score.h"

Score::Score(SDL_Renderer* renderer1, TTF_Font* font1,int x, int y){

    //make sure this is always at the end !
    font=font1;
    renderer=renderer1;
    surface = TTF_RenderText_Solid(font, "0", {0xFF, 0xFF, 0xFF, 0xFF});
    texture = SDL_CreateTextureFromSurface(renderer1, surface);


    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    //SDL Query fills the width and height values for us. otherwise, they are just zero!
    //so that why rect. w and h are the at bottom.
    rect.x= x;
    rect.y=y;
    rect.w=width;
    rect.h=height;



};




void Score::Update() {
    score++;
    if(score==8){
        Reset();
    }
    //this destroys the surface
    //SDL_FreeSurface(surface);
    //SDL_DestroyTexture(texture);
    destroy();

    surface = TTF_RenderText_Solid(font, std::to_string(score).c_str(), {0xFF, 0xFF, 0xFF, 0xFF});
    texture = SDL_CreateTextureFromSurface(renderer, surface);


    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    rect.w = width;
    rect.h = height;





}

void Score::Reset(){
    score=0;
}

SDL_Rect* Score:: getRect()
{
    return &rect;
}

void Score::destroy(){
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}


