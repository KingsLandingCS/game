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
        SDL_Quit();
        return -1;
    }

    // wait before closing
    SDL_Delay(3000);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

// 1️⃣ SDL_Init(SDL_INIT_VIDEO)
// cpp
// Copy
// Edit
// if (SDL_Init(SDL_INIT_VIDEO) < 0)
// SDL_Init is a function that initializes the SDL library.
// The parameter SDL_INIT_VIDEO tells SDL that we want to use video-related features (such as creating windows, rendering graphics, etc.).
// If initialization fails, SDL_Init returns a negative number (< 0).

// 3️⃣ Handling Errors with SDL_GetError()
// cpp
// Copy
// Edit
// cout << "SDL could not initialize! SDL_ERROR: " << SDL_GetError() << endl;
// If initialization fails, we print an error message.
// SDL_GetError() is a function that returns a string describing the last SDL error.
// Example output if SDL fails:
// yaml
// Copy
// Edit
// SDL could not initialize! SDL_ERROR: No available video device
// 4️⃣ Program Exits with return -1;
// cpp
// Copy
// Edit
// return -1;
// -1 is returned to indicate failure and exit the program.
// return 0; normally means successful execution.
// Here, since SDL failed to initialize, we return -1 to signal an error.

// 1️⃣ Creating an SDL Window
// cpp
// Copy
// Edit
// SDL_Window *window = SDL_CreateWindow(
//     "My first SDL Window",
//     SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//     800, 600,
//     SDL_WINDOW_SHOWN
// );
// SDL_CreateWindow(...) is used to create a window.
// It returns a pointer to an SDL_Window object.
// If the window creation fails, it returns nullptr (a null pointer).
// Breaking Down the Arguments
// cpp
// Copy
// Edit
// SDL_CreateWindow("My first SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
// Parameter	Meaning
// "My first SDL Window"	Title of the window (displayed in the title bar).
// SDL_WINDOWPOS_CENTERED	X position of the window (centered on the screen).
// SDL_WINDOWPOS_CENTERED	Y position of the window (centered on the screen).
// 800	Width of the window in pixels.
// 600	Height of the window in pixels.
// SDL_WINDOW_SHOWN	Flag that makes the window visible immediately.

// 3️⃣ Printing the Error Message
// cpp
// Copy
// Edit
// cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
// If SDL_CreateWindow fails, it prints an error message.
// SDL_GetError() returns the last SDL error message.
// Example Error Message
// yaml
// Copy
// Edit
// Window could not be created! SDL_Error: No available video device
// This error could occur if the system does not support graphics or SDL is not installed properly.

// 4️⃣ Cleaning Up SDL on Failure
// cpp
// Copy
// Edit
// SDL_Quit;
// If the window fails to create, we should clean up SDL.
// However, there is a bug here!
// ✅ Correct version:
// cpp
// Copy
// Edit
// SDL_Quit();
// ❌ Incorrect version:
// cpp
// Copy
// Edit
// SDL_Quit;
// SDL_Quit is a function, so it must be called with ().
// 5️⃣ Exiting the Program on Failure
// cpp
// Copy
// Edit
// return -1;
// The program exits with -1, signaling an error.

// Step-by-Step Explanation of the SDL_Delay, SDL_DestroyWindow, and SDL_Quit Block
// This block is responsible for: ✅ Pausing the program for 3 seconds.
// ✅ Destroying the SDL window to free memory.
// ✅ Quitting SDL to clean up resources.
// ✅ Returning 0 to indicate successful execution.

// 1️⃣ Pausing the Program with SDL_Delay(3000);
// cpp
// Copy
// Edit
// // wait before closing
// SDL_Delay(3000);
// What does SDL_Delay do?
// SDL_Delay(ms) pauses the program for the specified time in milliseconds.
// 3000 ms = 3 seconds
// This allows us to see the window before it closes.
// Why use SDL_Delay?
// If we don't delay, the program closes instantly, and we won’t see the window.
// SDL_Delay ensures the window stays open for 3 seconds before closing.
// 2️⃣ Destroying the SDL Window with SDL_DestroyWindow(window);
// cpp
// Copy
// Edit
// SDL_DestroyWindow(window);
// What does SDL_DestroyWindow do?
// Frees the memory allocated for the window.
// Prevents memory leaks (unused memory left allocated).
// Why destroy the window?
// If we don’t destroy the window, memory usage will increase every time a window is created.
// This is part of good resource management in SDL.
// What happens if we don’t call SDL_DestroyWindow?
// The operating system will eventually free the memory, but it’s bad practice to rely on that.
// This could cause performance issues or memory leaks in a larger application.
// 3️⃣ Quitting SDL with SDL_Quit();
// cpp
// Copy
// Edit
// SDL_Quit();
// What does SDL_Quit do?
// Cleans up all SDL subsystems (video, audio, timers, etc.).
// Releases any allocated resources.
// Should be called before exiting the program.
// Why is SDL_Quit important?
// Prevents resource leaks.
// Makes sure the system releases graphics resources properly.
// If we don’t call SDL_Quit, SDL may not function properly next time we use it.
// What happens if we don’t call SDL_Quit?
// The program might still work, but background resources won’t be freed.
// Other SDL programs might not initialize properly after running this program.
// 4️⃣ Returning 0 to Indicate Success
// cpp
// Copy
// Edit
// return 0;
// What does return 0; do?
// Signals that the program ended successfully.
// return -1; (used earlier) indicated failure.
// In C++, returning 0 from main() means successful execution.