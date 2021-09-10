#include <iostream>

int main(){
    int X = 20;
    int Y = 20;

    long long array[X + 1][Y + 1];
    
    for(int i = 0; i <= X; i++){
        array[i][0] = 1;
    }

    for(int i = 0; i <= Y; i++){
        array[0][i] = 1;
    }

    for(int i = 1; i <= X; i++){
        for(int j = 1; j <= Y; j++){
            array[i][j] = array[i - 1][j] + array[i][j - 1];
        }
    }

    std::cout << array[X][Y] << std::endl;

    return 0;
}
