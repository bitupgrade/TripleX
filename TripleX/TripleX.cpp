#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) { 
    /*
     _____    _       _     __   __
    |_   _|  (_)     | |    \ \ / /
      | |_ __ _ _ __ | | ___ \ V / 
      | | '__| | '_ \| |/ _ \/   \ 
      | | |  | | |_) | |  __/ /^\ \
      \_/_|  |_| .__/|_|\___\/   \/
               | |                 
               |_|                 
    */
    // Welcome messages that gets printed out into the terminal
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
    std::cout << std::endl;
}

bool PlayGame(int Difficulty) {
    PrintIntroduction(Difficulty);

    // Constant variables
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    // Store palyer guess
    int GuessA, GuessB, GuessC;
    std::cout << "Input: ";
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "You entered: " << GuessA << GuessB << GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if players input is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "\n\n*** Well done agent! You have extracted a file! Keep going! ***";
        return true;
    }
    else {
        std::cout << "\n\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }
}

int main(){
    srand(time(NULL)); // Create new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    
    std::cout << " \n _____    _       _     __   __" << std::endl;
    std::cout << "|_   _|  (_)     | |    \\ \\ / /" << std::endl;
    std::cout << "  | |_ __ _ _ __ | | ___ \\ V /" << std::endl;
    std::cout << "  | | '__| | '_ \\| |/ _ \\/   \\" << std::endl;
    std::cout << "  | | |  | | |_) | |  __/ /^\\ \\" << std::endl;
    std::cout << "  \\_/_|  |_| .__/|_|\\___\\/   \\/" << std::endl;
    std::cout << "           | |                 " << std::endl;
    std::cout << "           |_|                 " << std::endl;

    // Game rules
    std::cout << "\nEnter the code with a space between every number";
    std::cout << "\nExample: 1 2 3";

    while (LevelDifficulty <= MaxDifficulty){ // Loop game until all levels are completed

        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discrads the buffer
        
        if (bLevelComplete){
            ++LevelDifficulty;
        }
    }
    std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
    return 0;
}

