#include <iostream>

int main(){
    /* Print title */
    std::cout << "*** Reverse a String ***" << std::endl << std::endl;

    /* Get user input */
    std::string input;
    std::cout << "Enter a string: " << std::endl;
    std::getline(std::cin, input);

    /* Reverse string */
    for(int i = 0; i < input.length()/2; i++){
        char temp = input[input.length() - i - 1];
        input[input.length() - i - 1] = input[i];
        input[i] = temp;
    }

    /* Print reversed string */
    std::cout << std::endl << "Reversed: " << std::endl << input << std::endl;

    return 0;
}
