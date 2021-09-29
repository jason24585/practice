#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define LIMIT 28123

/* Check if number is abundant */
bool isAbundant(int x){
    int sum = 0;
    for(int i = 1; i <= sqrt(x); i++){
        if(x % i == 0){
            sum += i;
            if((x/i) != i && x/i != x){
                sum += x/i;
            }
        }
    }
    return sum > x;
}

int main(){
    int ans = 0;
    std::vector<int> abundants;
    for(int i = 0; i <= LIMIT; i++){
        bool found = false;
        /* Checks if number is the sum of two abundant numbers */
        for(int j = 0; j < abundants.size(); j++){
            if(isAbundant(i - abundants[j])){
                found = true;
                break;
            }
        }
        if(!found){
            ans += i;
        }
        if(isAbundant(i)){
            abundants.push_back(i);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
