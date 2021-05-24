constexpr auto GREEN = "\033[32m";
constexpr auto BOLDWHITE = "\033[1m\033[37m";

const int minNumberOfPlayers = 1;
const int maxNumberOfPlayers = 2;

void initGame();
void printMatches(int numMatches);
int main();
void displayWinner(int numPlayers, int currentPlayer);
void playNim();
int getNumberFromPlayer(std::string instruction, int minSelection, int maxSelection);