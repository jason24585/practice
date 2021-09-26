#include <iostream>
#include <map>
#include <cmath>

#define NUM 10000

/* Sum of proper divisors */
int d(int x){
    int sum = 0;
    for(int i = 1; i <= sqrt(x); i++){
        if(x % i == 0){
            sum += i;
            if((x/i) != i && x/i != x){
                sum += x/i;
            }
        }
    }
    return sum;
}

int main(){
    int ans = 0;
    /* Maps integer to sum of proper divisors */
    std::map<int, int> sums;
    for(int i = NUM; i > 0; i--){
        int sum = d(i);
        bool exists = false;
        for(auto itr = sums.begin(); itr != sums.end(); itr++){
            /* Check for pair of amicable numbers */
            if(i == itr->second && sum == itr->first){
                ans += itr->first;
                ans += itr->second;
                exists = true;
                break;
            }
        }
        if(!exists){
            sums.insert(std::make_pair(i, sum));
        }
    }

    std::cout << ans << std::endl;
    
    return 0;
}
