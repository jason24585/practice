#include <iostream>

int main(){
    int num = 20;
    bool divisible = true;

    while(true){
        num++;
        for(int i = 1; i <= 20; i++){
            if(num % i != 0){
                divisible = false;
                break;
            }
        }
        if(divisible){
            break;
        }
        divisible = true;
    }

    std::cout << num << std::endl;

    return 0;
}
