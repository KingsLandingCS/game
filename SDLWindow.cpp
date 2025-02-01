#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL could not initialize! SDL_ERROR: " << SDL_GetError() << endl;
        return -1;
    }

    // Create an SDL window
    SDL_Window *window = SDL_CreateWindow("My first SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        cout << "WIndow could not be created! SDL_Error: " << SDL_GetError() << endl;
        SDL_Quit;
        return -1;
    }

    // wait before closing
    SDL_Delay(3000);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}