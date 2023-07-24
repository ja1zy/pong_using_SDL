
#include <SDL2/SDL.h>
#include "Game.h"

int main() {

    Game game;
    //std::cout<<"not good";
    if(game.Init()){
        game.GameLoop();
    }else{
      //std::cout<<" good";
    }
    game.Shutdown();

    return 0;
}
