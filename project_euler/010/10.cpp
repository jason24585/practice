#include <iostream>
#include <vector>
#include <cmath>

int main(){
    long MAX = 2000000;
    long sum = 0;
    std::vector<int> primes;

    for(int i = 2; i < MAX; i++){
        bool isPrime = true;
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            primes.push_back(i);
            sum += i;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
