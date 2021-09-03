#include <iostream>
#include <random>
#include <algorithm>

/* Max number of incorrect guesses before game over */
const int MAX_GUESSES = 5;

/* Fixed set of words */
std::vector<std::string> words = {
    "apple",
    "grape",
    "melon",
    "orange",
    "banana",
    "pineapple",
    "watermelon",
    "strawberry"
};

/* Choose a random word from fixed set */
std::string setWord(){
    std::random_device r;
    std::mt19937 rng(r());
    std::uniform_int_distribution<int> distribute(0, words.size() - 1);
    int random = distribute(rng);

    return words[random];
}

/* Print incorrect letters */
void printMisses(std::vector<char> misses){
    std::cout << "MISSES: [ ";
    if(misses.size() > 0){
        for(int i = 0; i < misses.size() - 1; i++){
            std::cout << misses[i] << " | ";
        }
        std::cout << misses.back();
    }
    for(int i = misses.size(); i < MAX_GUESSES; i++){
        std::cout << " " << " | ";
    }
    std::cout << " ]" << std::endl;
}

/* Clears screen */
void clearScreen(){
    for(int i = 0; i < 100; i++){
        std::cout << std::endl;
    }
}

int main(){
    /* Print title */
    std::cout << "*** Hangman ***" << std::endl << std::endl;

    /* Word to be guessed */
    std::string word = "";
    /* String to store correctly guessed letters */
    std::string guesses = "";
    /* Number of letters correctly guessed */
    int correct = 0;
    /* Vector to store incorrectly guessed letters */
    std::vector<char> misses;
    /* Number of letters incorrectly guessed */
    int tally = 0;

    /* Choose the word to be guessed */
    /* TODO: Hide input; maybe use getch() */
    std::cout << "Enter the word or just press enter to get a random word: " << std::endl;
    std::getline(std::cin, word);
    if(word.length() == 0){
        word = setWord();
    }

    /* Initialize guessed string */
    for(int i = 0; i < word.length(); i++){
        guesses += "_";
    }

    clearScreen();

    while(true){
        /* Game over: Lose */
        if(tally == MAX_GUESSES){
            std::cout <<  guesses << std::endl;
            printMisses(misses);
            std::cout << "Game over! Sorry, you lose. :(" << std::endl;
            return 0;
        }

        /* Game over: Win */
        if(correct == word.length()){
            std::cout <<  guesses << std::endl;
            printMisses(misses);
            std::cout << "Game over! You won! :)" << std::endl;
            return 0;
        }

        /* Get user input */
        std::string input;
        std::cout <<  guesses << std::endl;
        printMisses(misses);
        std::cout << "Guess a letter: " << std::endl;
        std::getline(std::cin, input);
        if(input.length() != 1){
            clearScreen();
            continue;
        }
        char chara = input[0];

        bool found = false;
        bool guessed = false;
        /* Check if letter exists in the word */
        for(int i = 0; i < word.length(); i++){
            if(word.at(i) == chara){
                found = true;
                if(guesses[i] != chara){
                    correct++;
                    guesses[i] = chara;
                }
                else{
                    guessed = true;
                }
            }
        }

        clearScreen();

        /* Incorrect letter */
        if(!found){
            if(std::find(misses.begin(), misses.end(), chara) != misses.end()){
                std::cout << "You already guessed that letter." << std::endl;
            }
            else{
                std::cout << "Miss." << std::endl;
                misses.push_back(chara);
                tally++;
            }
        }
        /* Correct letter */
        else{
            if(guessed){
                std::cout << "You already guessed that letter." << std::endl;
            }
            else{
                std::cout << "Hit." << std::endl;
            }
        }
    }

    return 0;
}
