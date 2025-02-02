#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL Could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Interactive Window",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        SDL_Quit();
        return -1;
    }

    SDL_Event event;
    bool running = true;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

// Detailed Explanation of the Event Handling Loop in SDL
// The following block of code handles events such as user actions (like closing the window). It keeps the window open and interactive until the user chooses to close it.

// cpp
// Copy
// Edit
// SDL_Event event;
// bool running = true;

// while (running)
// {
//     while (SDL_PollEvent(&event))
//     {
//         if (event.type == SDL_QUIT)
//         {
//             running = false;
//         }
//     }
// }
// Step-by-Step Breakdown
// 1️⃣ Declaring the Event and Running Flag
// cpp
// Copy
// Edit
// SDL_Event event;
// bool running = true;
// SDL_Event event;:

// This creates a variable event of type SDL_Event. It is used to store event data (such as a mouse click, window close request, etc.) that SDL generates.
// An event represents user actions like key presses, mouse movements, and window events.
// bool running = true;:

// This boolean flag keeps track of whether the program should continue running.
// Initially set to true, it allows the program to enter the event loop and keep running until the user closes the window.
// 2️⃣ Outer while (running) Loop – Continuously Running the Program
// cpp
// Copy
// Edit
// while (running)
// {
//     // inner loop for event handling
// }
// The outer loop will keep the program running as long as the running flag is true.
// If the user clicks the close button on the window, we will change the value of running to false, causing this loop to stop, and the program will exit.
// 3️⃣ Inner while (SDL_PollEvent(&event)) Loop – Polling Events
// cpp
// Copy
// Edit
// while (SDL_PollEvent(&event))
// {
//     // Check for SDL_QUIT event
// }
// SDL_PollEvent(&event) is a function provided by SDL to retrieve events from the event queue.
// Event Queue: SDL keeps a queue of events that occur while the program is running, such as keyboard input, mouse movements, and window events.
// SDL_PollEvent will remove the first event in the queue and store it in the event variable.
// The loop continues as long as there are events in the queue to be processed.
// 4️⃣ Checking the Event Type: Window Close (SDL_QUIT)
// cpp
// Copy
// Edit
// if (event.type == SDL_QUIT)
// {
//     running = false;
// }
// event.type == SDL_QUIT:
// This condition checks if the event type is SDL_QUIT, which occurs when the user tries to close the SDL window (by clicking the close button).
// SDL_QUIT is a predefined event type in SDL, signaling that the user intends to exit the application.
// running = false;:
// When a SDL_QUIT event is detected (e.g., the window close button is clicked), we set running to false.
// This stops the outer while (running) loop from running, effectively closing the application.
// 🔹 Summary of Event Loop
// SDL_Event event; creates an event variable.
// running = true; keeps the program running.
// while (running) keeps the program in an infinite loop, checking for events.
// SDL_PollEvent(&event) polls for events in the event queue.
// If a SDL_QUIT event (user closing the window) is detected, running = false; stops the loop and closes the window.
// 💡 Key Points
// The event handling loop allows SDL programs to stay interactive by responding to user input.
// SDL_PollEvent(&event) processes events one by one in the queue.
// The loop checks for a window close event (SDL_QUIT) and stops the program when this event occurs.
// Would you like to learn how to handle keyboard inputs or mouse events in the SDL event loop as well? 🎮

// You said:
// I don't understand that why are we passing &event here "SDL_PollEvent(&event)"
// ChatGPT said:
// ChatGPT
// Why Use &event in SDL_PollEvent(&event)?
// In C++, when you pass a variable to a function, you can choose to pass it by value or pass it by reference.

// In the case of SDL_PollEvent(&event), we are passing the event variable by reference using the address of the variable (&event).

// Let’s break this down:
// 1️⃣ What is SDL_Event event;?
// cpp
// Copy
// Edit
// SDL_Event event;
// This creates an instance of SDL_Event, which is a struct (or structure) that holds information about an event that occurs in the SDL program. The event variable will store things like:
// Key press events
// Mouse movement or button clicks
// Window events (like closing the window)
// 2️⃣ Passing By Reference (&event)
// cpp
// Copy
// Edit
// SDL_PollEvent(&event);
// The & symbol in &event is the address-of operator. It gets the memory address of the event variable.
// By passing the address of event to SDL_PollEvent(), we allow the function to modify the contents of the event variable directly.
// Why do we pass &event by reference instead of by value?
// Memory Efficiency: SDL_Event can store quite a bit of information (for example, mouse position, keyboard state, etc.). By passing the address of the variable, we avoid making a copy of the entire SDL_Event structure, which would take more memory.
// Direct Modification: SDL_PollEvent needs to update the event variable with the latest event data (like a mouse click or keyboard press). To do this, the function needs to have direct access to the original event variable. If we pass by reference, any changes made inside SDL_PollEvent will directly affect the event variable in the main program.
// 3️⃣ How Does SDL_PollEvent Work?
// cpp
// Copy
// Edit
// while (SDL_PollEvent(&event))
// {
//     // event.type will now hold the event type (like SDL_QUIT)
// }
// SDL_PollEvent(&event) checks the event queue and retrieves the next event (if available).
// It fills the event struct with details about the event, such as:
// Type of event (key press, window close, etc.)
// Key or mouse information if relevant.
// By passing the memory address of event, SDL_PollEvent modifies the contents of that variable, updating it with the most recent event.

// 4️⃣ Why Not Pass event by Value?
// If you were to pass event by value (i.e., SDL_PollEvent(event)), then:

// The event variable inside the function would be a copy of the original event.
// Any changes made to that copy wouldn't be reflected in the original event in your program.
// SDL needs to modify the original event to give you updated event data, so passing by reference is necessary.
// Example
// Let’s take an analogy to understand better: Imagine you are a manager (your program), and you have a team member (the event variable). You need to update their task list based on new events (like a new mouse click or key press).

// If you send the team member to another office (pass by value), they can’t update your task list. You would only get a copy of their task list, not the updated one.
// Instead, you give them a direct phone line (pass by reference) to your office. They can now directly modify your task list and report back with the latest updates.
// 💡 In Summary:
// &event is used to pass the address of the event variable to SDL_PollEvent.
// This allows SDL_PollEvent to directly modify the event variable, which is necessary to update it with the latest event data.
// Passing by reference is more efficient and ensures that changes are reflected in the original event.
// Would you like to know more about other ways to handle events or work with different types of inputs in SDL?