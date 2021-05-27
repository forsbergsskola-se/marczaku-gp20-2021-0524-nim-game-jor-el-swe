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
    int valueField[9] = {2,3,5,7,11,13,17,19,23};
    int currentPlayer = 0, player1Score = 1, player2Score = 1, numberFilledBoxes=0;

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
                    playField[playerSelection - 1] = currentPlayer == 1 ? 'X' : 'O';
                    //update player score to check for win condition
                    currentPlayer == 1 ? player1Score *= valueField[playerSelection - 1] : player2Score *= valueField[playerSelection - 1];
                    cout << "player 1 score: " << player1Score << endl;
                    cout << "player 2 score: " << player2Score << endl;
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


        if (CalculateWinner(player1Score, currentPlayer) || CalculateWinner(player2Score, currentPlayer) || GameIsDraw(numberFilledBoxes))
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

bool CalculateWinner(int playerScore, int currentPlayer)
{
    //prime numbers used to calculate winner
    /*      2, 3, 5, 
            7, 11, 13, 
            17, 19, 23*/

    int valueField[8] = { 2*3*5, 7*11*13, 17*19*23, 2*7*17, 3*11*19, 5*13*23, 2*11*23, 5*11*17};

    bool winnerPlayer = false;

    for (int i = 0; i < 8; i++) {
        if (playerScore % valueField[i] == 0) {
            winnerPlayer = true;
            cout << "We have a winner! Player: " << currentPlayer << endl;
            return true;
        }   
    }

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
