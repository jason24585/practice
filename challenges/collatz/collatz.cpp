#include <iostream>
#include <sstream>

int main(){
    /* Print title */
    std::cout << "*** Collatz Conjecture ***" << std::endl << std::endl;

    /* Get user input */
    int inputnum;
    std::string input;
    std::cout << "Enter an integer: " << std::endl;
    while (std::getline(std::cin, input)){
        std::stringstream ss(input);
        if (ss >> inputnum){
            if (ss.eof()){   
                break;
            }
        }
        std::cerr << "Invalid input, try again." << std::endl;
    }

    long num = inputnum;

    /* Apply Collatz conjecture */
    while(num != 1){
        /* Print num */
        std::cout << num << " ";

        /* Even */
        if(num % 2 == 0){
            num /= 2;
        }
        /* Odd */
        else{
            num = (num * 3) + 1;
        }
    }

    std::cout << num << std::endl;
    
    return 0;
}
