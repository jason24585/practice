#include <iostream>
#include <cmath>

int main(){
    int NUM_DIVISORS = 500;
    int index = 1;
    int num = 0;
    int divisors = 0;

    while(NUM_DIVISORS > divisors){
        num += index;
        index++;

        divisors = 0;
        for(int i = 1; i <= sqrt(num); i++){
            if(num % i == 0){
                if(num/i == i){
                    divisors++;
                }
                else{
                    divisors+=2;
                }
            }
        }
    }

    std::cout << num << std::endl;

    return 0;
}
