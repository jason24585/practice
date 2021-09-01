#include <iostream>

int main(){
    int palindrome = 0;
    bool isPalindrome = true;

    for(int num1 = 999; num1 > 99; num1--){
        for(int num2 = 999; num2 > 99; num2--){
            int product = num1 * num2;
            std::string string = std::to_string(product);
            for(int i = 0; i < string.length()/2; i++){
                if(string[i] != string[string.length() - i - 1]){
                    isPalindrome = false;
                    break;
                }
            }
            if(isPalindrome){
                if(product > palindrome){
                    palindrome = product;
                }
            }
            isPalindrome = true;
        }
    }

    std::cout << palindrome << std::endl;

    return 0;
}
