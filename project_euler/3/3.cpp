#include <iostream>
#include <cmath>
#include <vector>

int main(){
    long num = 600851475143;
    std::vector<int> factors;

    while(true){
        if(num % 2 == 0){
            factors.push_back(2);
            num /= 2;
            continue;
        }
        for(int i = 3; i <= sqrt(num); i+=2){
            if(num % i == 0){
                factors.push_back(i);
                num /= i;
                continue;
            }
        }
        factors.push_back(num);
        break;
    }

    std::cout << factors.back() << std::endl;

    return 0;
}
