// nim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h> 
#include "nim.h"

using namespace std;

constexpr auto GREEN = "\033[32m";
constexpr auto BOLDWHITE = "\033[1m\033[37m" ;

int main()
{
    playNim();
}

void playNim() {
    cout << GREEN;
    /* initialize random seed: */
    srand(time(NULL));

    //Implements the game of Nim: 1/2 players; 24 matches;
    int numMatches = 24;
    int numPlayers = 0;
    int currentPlayer = 0;

    cout << "Welcome to Nim!\n";
    cout << "Your objective is to make the other player take the last match.\n";

    while (numPlayers != 1 && numPlayers != 2)
    {
        cout << ("Enter Number of Players (1/2): ");
        cin >> numPlayers;
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "You choose " << numPlayers << " number of players" << endl;

    //players take turns to draw matches; may draw 1,2 or 3 matches (not more or less); 
    while (true)
    {
        cout << endl;
        cout << "Matches left: "<< numMatches<<"\n";
        //make pritty ASCII art of matches
        for (int i = 0; i < numMatches; i++)
        {
            cout << BOLDWHITE;
            cout << "| ";
        }
        cout << GREEN;
        cout << endl;
        cout << endl;


        int playerSelection = 0;
        if (numPlayers == 2 || currentPlayer == 0)
        {

            while (playerSelection != 1 && playerSelection != 2 && playerSelection != 3)
            {
                cout << "Player " << currentPlayer + 1 << ", choose number of matches (1-3):";

                cin >> playerSelection;
                if (!cin)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
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


