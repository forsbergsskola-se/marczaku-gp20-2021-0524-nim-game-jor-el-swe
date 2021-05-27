// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "tictactoe.h" 
using namespace std;

int main()
{
    char playField[9];

    for (int i=0; i< 9; i++)
    {
        playField[i] = ' ';
    }
    while (true) {

        //drawPlayingField();
        int playerSelection = getNumberFromPlayer("choose a box for your placement: ", 1, 9);

        cout << "you chose: " << playerSelection << endl;
        cout << endl;
    }



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
