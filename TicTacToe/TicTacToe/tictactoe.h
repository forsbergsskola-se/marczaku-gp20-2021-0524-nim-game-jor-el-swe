#pragma once
#include <iostream>
using namespace std;

constexpr auto GREEN = "\033[32m";
constexpr auto BOLDWHITE = "\033[1m\033[37m";



const int minNumberOfPlayers = 1;
const int maxNumberOfPlayers = 2;


int main();

int getNumberFromPlayer(string instruction, int minSelection, int maxSelection);
void initGame();
bool CalculateWinner();
bool GameIsDraw(int numberFilledBoxes);
void drawPlayingField(char *playField);