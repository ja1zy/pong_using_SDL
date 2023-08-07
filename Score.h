//
// Created by Jasdeep saran on 2023-08-03.
//

#ifndef PONG_TUTORIAL_SCORE_H
#define PONG_TUTORIAL_SCORE_H

#include "Utils.h"

class Score {


public:
    Score(SDL_Renderer* renderer, TTF_Font* font, int x, int y);
    void Update();
     SDL_Rect * getRect();
     void Reset();
     void destroy();

    SDL_Texture* texture;

private:
    SDL_Rect rect;
    int height;
    int width;
    int score=0;
    const char* scores[8]{};
    SDL_Surface* surface;

    SDL_Renderer* renderer;
    TTF_Font* font;
};


#endif //PONG_TUTORIAL_SCORE_H
