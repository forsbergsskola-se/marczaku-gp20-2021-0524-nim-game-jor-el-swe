constexpr auto GREEN = "\033[32m";
constexpr auto BOLDWHITE = "\033[1m\033[37m";

void initGame();
void printMatches(int numMatches);
int main();
void displayWinner(int numPlayers, int currentPlayer);
void playNim();