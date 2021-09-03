#include <iostream>
#include <vector>
#include <cmath>

int main(){
    std::vector<int> primes;
    int n = 10001;
    int num = 2;
    bool isPrime = true;

    while(true){
        for(int i = 2; i <= sqrt(num); i++){
            if(num % i == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            primes.push_back(num);
        }
        if(primes.size() == n){
            break;
        }
        isPrime = true;
        num++;
    }

    std::cout << primes.back() << std::endl;

    return 0;
}
