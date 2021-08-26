#include <iostream>
#include <random>

int main(){
    /* Print title */
    std::cout << "*** Heads or Tails ***" << std::endl << std::endl;

    /* Get user input */
    std::cout << "Heads or tails? [h/t]" << std::endl;
    std::string input;
    while(std::cin){
        std::getline(std::cin, input);
        if(!input.compare("h") || !input.compare("t")){
            break;
        }
        std::cerr << "Invalid input, try again." << std::endl;
    }
    char choice = input[0];
    std::cout << "You guessed ";
    if(choice == 'h'){
        std::cout << "heads." << std::endl;
    }
    else{
        std::cout << "tails." << std::endl;
    }

    /* Generate random value */
    std::random_device r;
    std::mt19937 rng(r());
    std::uniform_int_distribution<int> distribute(0,1);

    /* 0 for tails, 1 for heads */
    char result;
    if(distribute(rng)){
        std::cout << "It's heads.";
        result = 'h';
    }
    else{
        std::cout << "It's tails.";
        result = 't';
    }

    /* Print result */
    if(result == choice){
        std::cout << " :)" << std::endl;
    }
    else{
        std::cout << " :(" << std::endl;
    }

    return 0;
}
