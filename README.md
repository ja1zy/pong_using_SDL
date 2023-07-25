# pong_using_SDL
PONG_TUTORIAL
This project uses SDL2 to create Pong.

using SDL2, I followed along a tuturoial to create pong using sdl2. I also took my own liberties.

Step 1&2: made use of main and game class, aswell as Game.h.

Step3 (start here) making the paddles and how the paddle moves. 
first thing to note. the x-posiiton of the paddles is constant. 
It is only the Y-position that moves. Position Y is the start of the paddle(at the very top). 
How the paddles move: *happenings in the game class. while the gameloop() method continues, 
the handlevents function gets the pointer SDL_GetKeyboardState(), 
this is the button pressed upon the current frame/event. depending on the button pressed, 
the paddle moves. once keystate is pressed, 
then the instance of the class moves in the direction using the setDir() fuction which updates the y position.
setDir() is a getter as x and y are private varaibles.
