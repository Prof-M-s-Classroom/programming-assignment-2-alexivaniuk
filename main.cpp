#include <iostream>
#include <fstream>
#include <string>
#include "GameDecisionTree.h"
using namespace std;
int main() {
    GameDecisionTree<Story*> *myGame = new GameDecisionTree<Story*>();

    string filename = "story.txt";  // Specify the input file
    char delimiter = '|';                // '|' is the delimiter, change if needed

    // Load the story data from the file
    myGame->loadStoryFromFile(filename, delimiter);

    // Start the game
    myGame->playGame();

    return 0;
}