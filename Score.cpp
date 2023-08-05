//
// Created by Jasdeep saran on 2023-08-03.
//

#include "Score.h"

Score::Score(SDL_Renderer* renderer, TTF_Font* font,int x, int y){

    rect.x= x;
    rect.y=y;
    rect.w=width;
    rect.h=height;
    renderer1=renderer;
    surface = TTF_RenderText_Solid(font, "0", {0xFF, 0xFF, 0xFF, 0xFF});
    texture = SDL_CreateTextureFromSurface(renderer1, surface);
};




void Score::Update() {
    score++;
}

void Score::Reset(){
    score=0;
}

