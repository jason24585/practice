#include <iostream>
#include <limits>

int main(){
    /* Print title */
    std::cout << "*** Fizz Buzz ***" << std::endl << std::endl;

    /* Get user input */
    int num;
    std::cout << "Print how many numbers? " << std::endl;
    while(!(std::cin >> num)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Invalid input, try again." << std::endl;
    }

    /* Fizz Buzz */
    bool printNum = true;
    std::cout << std::endl;
    for(int i = 1; i <= num; i++){
        if(i % 3 == 0){
            std::cout << "Fizz";
            printNum = false;
        }
        if(i % 5 == 0){
            std::cout << "Buzz";
            printNum = false;
        }
        if(printNum){
            std::cout << i;
        }
        std::cout << std::endl;
        printNum = true;
    }

    return 0;
}
