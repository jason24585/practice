#include <iostream>

int main(){
    int term1 = 1;
    int term2 = 2;
    int temp;
    int sum = 0;

    while(term2 <= 4000000){
        if(term2 % 2 == 0){
            sum += term2;
        }
        temp = term2;
        term2 += term1;
        term1 = temp;
    }

    std::cout << sum << std::endl;
    return 0;
}
