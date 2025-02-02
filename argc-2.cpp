#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    // Add fake arguments
    const char *extraArgs[] = {"extra1", "extra2", "extra3"};
    int extraArgCount = sizeof(extraArgs) / sizeof(extraArgs[0]);

    cout << "Original Number of arguments: " << argc << endl;

    // Adjust argc and create a new argument array
    argc += extraArgCount;
    char **newArgv = new char *[argc];

    // copy original arguments
    for (int i = 0; i < argc - extraArgCount; i++)
    {
        newArgv[i] = argv[i];
    }

    // Add extra arguments
    for (int i = 0; i < extraArgCount; i++)
    {
        newArgv[argc - extraArgCount + i] = const_cast<char *>(extraArgs[i]);
    }

    // Print updated arguments
    cout << "Updated Number of arguments: " << argc << endl;
    for (int i = 0; i < argc; i++)
    {
        cout << "Argument " << i << ": " << newArgv[i] << endl;
    }

    // clean up allocated memory
    delete[] newArgv;

    return 0;
}