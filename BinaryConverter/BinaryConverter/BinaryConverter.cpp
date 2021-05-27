// BinaryConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include "binary.h"
using namespace std;
/*
Write a Program that reads (cin) decimal Integer numbers (positive only) And Oututs the Binary representation of that number: 0b110

Firstly, implement the function the way we know, with division and modulo.
Secondly, implement the function using binary operations.
Tip: Both exercises will be a lot easier, if you output one character at a time!
*/
int main()
{
    int intToConvert = getNumberFromPlayer("Enter a number to convert to binary representation ", 0, INT32_MAX);
    cout << "You want to convert: " << intToConvert << endl;
}

int getNumberFromPlayer(string instruction, int minSelection, int maxSelection)
{
    int playerSelection = -1;
    bool validInput = false;
    while (!validInput || playerSelection < minSelection || playerSelection > maxSelection)
    {
        validInput = true;
        cout << instruction;
        cin >> playerSelection;
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validInput = false;
        }
    }
    return playerSelection;
}
