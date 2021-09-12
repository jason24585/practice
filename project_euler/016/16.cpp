#include <iostream>
#include <cmath>
#include <sstream>

int main(){
    double NUM = pow(2, 1000);

    std::stringstream ss;
    ss << std::fixed << NUM;

    std::string numstr = ss.str();

    int ans = 0;
    int index = 0;
    while(numstr[index] != '.'){
        ans += int(numstr[index] - '0');
        index++;
    }

    std::cout << ans << std::endl;

    return 0;
}
