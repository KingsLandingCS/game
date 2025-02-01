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

// Derived class: Player
class Player : public GameObject
{
public:
    // Use the base class constructor to initialize.
    Player(int x, int y, int w, int h, SDL_Color color)
        : GameObject(x, y, w, h, color) {}

    // Optionally override the render method.
    void render(SDL_Renderer *renderer) override
    {
        // Here we call the base class render.
        GameObject::render(renderer);
        // Additional rendering for the player can be added here if needed.
    }
};

// Derived class: Enemy
class Enemy : public GameObject
{
public:
    // Use the base class constructor to initialize.
    Enemy(int x, int y, int w, int h, SDL_Color color)
        : GameObject(x, y, w, h, color) {}

    // Optionally override the render method.
    void render(SDL_Renderer *renderer) override
    {
        // Here we call the base class render.
        GameObject::render(renderer);
        // Additional rendering for the enemy can be added here if needed.
    }
};

int main()
{
    // Initialize SDL with video support
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cout << "SDL_Init Error: " << SDL_GetError() << endl;
        return 1;
    }

    // Create a window
    SDL_Window *win = SDL_CreateWindow("Inheritance Example",
                                       100, 100, 640, 480,
                                       SDL_WINDOW_SHOWN);
    if (win == nullptr)
    {
        cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    // Create a renderer associated with the window
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1,
                                                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        SDL_DestroyWindow(win);
        cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    // Create a Player and an Enemy object using our derived classes.
    // The Player will be drawn in green and the Enemy in red.
    Player player(50, 50, 100, 100, {0, 255, 0, 255});
    Enemy enemy(300, 200, 100, 100, {255, 0, 0, 255});

    // Main loop flag
    bool quit = false;
    SDL_Event event;

    // Main event/rendering loop
    while (!quit)
    {
        // Process events
        while (SDL_PollEvent(&event))
        {
            // If the user closes the window, exit the loop.
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        // Clear the screen to black
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Create an array of GameObject pointers.
        // Notice we can store both Player and Enemy objects here because of inheritance.
        GameObject *objects[2];
        objects[0] = &player;
        objects[1] = &enemy;

        // Use polymorphism: call render on each object.
        for (int i = 0; i < 2; i++)
        {
            objects[i]->render(renderer);
        }

        // Update the screen with any rendering performed since the previous call.
        SDL_RenderPresent(renderer);
    }

    // Clean up resources before exiting.
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
