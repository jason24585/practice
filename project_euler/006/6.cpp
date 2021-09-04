#include <iostream>
#include <cmath>

int main(){
    int n = 100;
    int sum1 = 0;
    int sum2 = 0;

    for(int i = 1; i <= n; i++){
        sum1 += pow(i, 2);
        sum2 += i;
    }
    sum2 = pow(sum2, 2);

    std::cout << sum2 - sum1 << std::endl;

    return 0;
}
