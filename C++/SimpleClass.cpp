#include <iostream>
using namespace std;

class Player
{
public:
    string name;
    int health;

    Player(string n, int h)
    {
        name = n;
        health = h;
    }

    void display()
    {
        cout << "Player: " << name << ", Health: " << health << endl;
    }
};

int main()
{
    Player p1("Hero", 100);
    p1.display();

    return 0;
}