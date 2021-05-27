// BinaryConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}

int getNumberFromPlayer(string instruction, int minSelection, int maxSelection)
{
    int playerSelection = -1;
    while (playerSelection < minSelection || playerSelection > maxSelection)
    {
        cout << instruction;
        cin >> playerSelection;
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return playerSelection;
}
