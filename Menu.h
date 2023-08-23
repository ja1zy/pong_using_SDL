//
// Created by Jasdeep saran on 2023-08-21.
//

#ifndef PONG_TUTORIAL_MENU_H
#define PONG_TUTORIAL_MENU_H
#include "Utils.h"

class Menu {
public:
    Menu(SDL_Renderer* renderer, TTF_Font* font, int x, int y);
    void Update();
    SDL_Rect * getRect();
    void destroy();
    SDL_Texture* texture;
    void setPause(bool paused);
    bool getPause();



private:
    SDL_Rect rect;
    int height;
    int width;
    bool pause;
    SDL_Surface* surface;

    SDL_Renderer* renderer;
    TTF_Font* font;





};


#endif //PONG_TUTORIAL_MENU_H
