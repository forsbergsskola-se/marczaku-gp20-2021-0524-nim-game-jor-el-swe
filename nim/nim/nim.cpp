// nim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "nim.h"

using namespace std;

int main()
{
    initGame();
    playNim();
}

void playNim() {
    //Implements the game of Nim: 1/2 players; 24 matches;
    int numMatches = 24;
    int currentPlayer = 0;

    int numPlayers = getNumberFromPlayer("Enter Number of Players (1/2): ", minNumberOfPlayers, maxNumberOfPlayers);
    cout << "You choose " << numPlayers << " number of players" << endl;

    //players take turns to draw matches; may draw 1,2 or 3 matches (not more or less); 
    while (true)
    {
        printMatches(numMatches);

        int playerSelection = 0;
        if (numPlayers == 2 || currentPlayer == 0)
        {
            std::ostringstream oss;
            oss << "Player " << currentPlayer + 1 << ", choose number of matches (1-3):";
            std::string instruction = oss.str();

            playerSelection = getNumberFromPlayer(instruction, 1, 3);
        }
        else //ai's turn
        {
            /* generate secret number between 1 and 3: */
            int random = rand() % 3 + 1;
            playerSelection = min(random, numMatches);
            cout << "AI chooses " << playerSelection << " matches\n";
        }

        currentPlayer++;
        currentPlayer &= 0x1;

        numMatches -= playerSelection;

        if (numMatches < 1)
        {
            break;
        }
    }
    //player who has to take last match loses;
    displayWinner(numPlayers, currentPlayer);
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

void initGame()
{
    cout << GREEN;
    /* initialize random seed: */
    srand(time(NULL));

    cout << "Welcome to Nim!\n";
    cout << "Your objective is to make the other player take the last match.\n";
}

void printMatches(int numMatches)
{
    cout << endl;
    cout << "Matches left: " << numMatches << "\n";
    //make pritty ASCII art of matches
    for (int i = 0; i < numMatches; i++)
    {
        cout << BOLDWHITE;
        cout << "| ";
    }
    cout << GREEN;
    cout << endl;
    cout << endl;
}

void displayWinner(int numPlayers, int currentPlayer)
{
    if (numPlayers == 2)
    {
        cout << "Player" << currentPlayer + 1 << " wins!";
    }
    else
    {
        if (currentPlayer == 0)
        {
            cout << "Player wins!";
        }
        else
        {
            cout << "AI wins!" << endl;
        }

    }
}


