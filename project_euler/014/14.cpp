#include <iostream>

int main(){
    /* Max starting number */
    int MAX = 1000000;

    /* Track answer and length of its Collatz chain */
    int ans = 0;
    int anslen = 0;

    for(int i = MAX - 1; i > 0; i--){
        long temp = i;
        int len = 1;

        /* Collatz sequence */
        while(temp != 1){
            if(temp % 2 == 0){
                temp /= 2;
            }
            else{
                temp = (temp * 3) + 1;
            }
            len++;
        }

        /* Check if longest chain */
        if(len > anslen){
            ans = i;
            anslen = len;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
