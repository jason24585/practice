#include <iostream>
#include <algorithm>

#define NUM 1000000

/* Get next lexicographic permutation */
void nextPermutation(int digits[], int len){
    /* Check i digits from the right */
    for(int i = 1; i <= len; i++){
        /* Loop through digits starting from the right */
        for(int j = 0; j < i; j++){
            int index = len - j - 1;
            int temp = digits[index];
            /* Check if any digits are larger than digits on the left */
            for(int k = index; k > len - i - 1; k--){
                /* If so, swap digits and sort the rest of the right digits */
                if(temp > digits[k]){
                    digits[index] = digits[k];
                    digits[k] = temp;
                    std::sort(digits + k + 1, digits + len);
                    return;
                }
            }
        }
    }
    /* This is the last permutation */
    return;
}

int main(){
    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(digits)/sizeof(digits[0]);

    for(int i = 1; i < NUM; i++){
        nextPermutation(digits, len);
    }

    for(int i = 0; i < len; i++){
        std:: cout << digits[i];
    }
    std::cout << std::endl;
    
    return 0;
}
