#include <iostream>
#include <sstream>

int main(){
    /* Print title */
    std::cout << "*** Temperature Converter ***" << std::endl << std::endl;

    /* Get user input */
    std::string input;

    std::cout << "Enter input temperature unit(Farenheit[f], Celcius[c], Kelvin[k]): " << std::endl;
    while(true){
        std::getline(std::cin, input);
        if(!input.compare("f") || !input.compare("c") || !input.compare("k")){
            break;
        }
        std::cerr << "Invalid, try again." << std::endl;
    }
    char in = input[0];

    std::cout << "Enter output temperature unit(Farenheit[f], Celcius[c], Kelvin[k]): " << std::endl;
    while(true){
        std::getline(std::cin, input);
        if(!input.compare("f") || !input.compare("c") || !input.compare("k")){
            break;
        }
        std::cerr << "Invalid, try again." << std::endl;
    }
    char out = input[0];

    std::cout << "Enter input temperature value: " << std::endl;
    /* Check if input is a double using stringstream */
    double invalue;
    while (std::getline(std::cin, input)){
        std::stringstream ss(input);
        if (ss >> invalue){
            if (ss.eof()){   
                break;
            }
        }
        std::cerr << "Invalid, try again." << std::endl;
    }

    /* Convert input temperature value to Farenheit */
    if(in == 'k'){
        invalue -= 273.15;
    }
    if(in == 'c' || in == 'k'){
        invalue = ((invalue*9)/5) + 32;
    }

    /* Convert input temperature value to desired output */
    if(out == 'c' || out == 'k'){
        invalue = ((invalue - 32) * 5)/9;
    }
    if(out == 'k'){
        invalue += 273.15;
    }

    /* Print result */
    std::cout << "Result is: " << invalue << " " << out << std::endl;

    return 0;
}
