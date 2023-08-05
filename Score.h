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
    void Reset();

private:
    SDL_Rect rect;
    int height;
    int width;
    int score=0;
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Renderer renderer1;
};


#endif //PONG_TUTORIAL_SCORE_H
