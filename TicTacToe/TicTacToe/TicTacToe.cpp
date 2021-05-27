// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include "tictactoe.h" 
using namespace std;

int main()
{
    //char playField[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    char playField[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    int currentPlayer = 0, player1Score = 0, player2Score = 0, numberFilledBoxes=0;

    initGame();

    int numPlayers = getNumberFromPlayer("Enter Number of Players (1/2): ", minNumberOfPlayers, maxNumberOfPlayers);
    cout << "You choose " << numPlayers << " number of players" << endl;

    while (true) {
        int playerSelection = 0;
        if (numPlayers == 2 || currentPlayer == 0)
        {
            std::ostringstream oss;
            oss << "Player " << currentPlayer + 1 << ", choose a box:";
            std::string instruction = oss.str();

            bool validInput = false;
            while (!validInput) {
                drawPlayingField(playField);
                playerSelection = getNumberFromPlayer(instruction, 1, 9);
                if (playField[playerSelection-1] == ' ') {
                    playField[playerSelection-1] = (char)playerSelection+48;
                    validInput = true;
                }
            }
           
            cout << "you chose: " << playerSelection << endl;
            cout << endl;
        }
        else //ai's turn
        {
            /* generate secret number between 1 and 9: */
            int random = rand() % 9 + 1;
            playerSelection = random;
            cout << "AI chooses " << playerSelection << " matches\n";
        }

        currentPlayer++;
        currentPlayer &= 0x1;
        numberFilledBoxes++;


        if (CalculateWinner() || GameIsDraw(numberFilledBoxes))
        {
            drawPlayingField(playField);
            break;
        }

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


void initGame()
{
    cout << GREEN;
    /* initialize random seed: */
    srand(time(NULL));

    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Your objective is to get three in a row.\n";
}

bool CalculateWinner()
{
    return false;
}

bool GameIsDraw(int numberFilledBoxes)
{
    if(numberFilledBoxes == 9)
    {
        cout << "Game was a draw";
        return true;
    }
    return false;
}

void drawPlayingField(char* playField)
{
    cout << endl << "-------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "|";
        for (int j = 0; j < 3; j++) {
            cout << playField[i*3+j] << "|";;
        }
        cout << endl<< "-------"<<endl;

    }
}
