#include <iostream>

int main(){
    int num = 1000;

    for(int i = 1; i < num; i++){
        for(int j = 1; j < num; j++){
            int k = num - i - j;
            if((i * i + j * j) == (k * k)){
                std::cout << i * j * k << std::endl;
                return 0;
            }
        }
    }
    return 0;
}
