//
// Created by Jasdeep saran on 2023-08-21.
//

#include "Menu.h"

 Menu:: Menu(SDL_Renderer* renderer1, TTF_Font* font1,int x, int y){

    renderer=renderer1;
     font=font1;

     surface = TTF_RenderText_Solid(font, "Game Paused: Press G to resume", {0xFF, 0xFF, 0xFF, 0xFF});
     texture = SDL_CreateTextureFromSurface(renderer1, surface);


     SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

     //SDL Query fills the width and height values for us. otherwise, they are just zero!
     //so that why rect. w and h are the at bottom.
     rect.x= x;
     rect.y=y;
     rect.w=width;
     rect.h=height;
     pause =false;


};


bool Menu::getPause() {
    return pause;
}
void Menu::setPause(bool paused) {
    pause=paused;
}

void Menu::Update() {
    if(!pause){
        destroy();
    }
}

SDL_Rect* Menu::getRect() {
    return &rect;
}

void Menu::destroy(){
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

