#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

// Base class: GameObject
class GameObject
{
public:
    // Position and size
    int x, y, w, h;

    // Color represented as SDL_Color (Which holds r, g, b, a)
    SDL_Color color;

    // Constructor to initialize the object
    GameObject(int x, int y, int w, int h, SDL_Color color)
        : x(x), y(y), w(w), h(h), color(color) {}

    // Virtual render method: derived classes can override this.
    virtual void render(SDL_Renderer *renderer)
    {
        // Create an SDL_Rect using the object's properties.
        SDL_Rect rect = {x, y, w, h};

        // Set the drawing color to this object's color.
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        // Render a filled rectangle representing this object.
        SDL_RenderFillRect(renderer, &rect);
    }

    // A virtual destructor to ensure proper cleanup in derived classes.
    virtual ~GameObject() {}
};