#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>

#define NUM 100

/* Reverse a string */
std::string reverse(std::string input){
    for(int i = 0; i < input.length()/2; i++){
        char temp = input[input.length() - i - 1];
        input[input.length() - i - 1] = input[i];
        input[i] = temp;
    }

    return input;
}

/* Adds large sum; terms must be integers stored as reversed strings in nums; max_digits stores length of largest term */
std::vector<char> add(std::vector<std::string> nums, int max_digits){
    /* Position of digits being added */
    int curr_digit = 0;

    std::vector<char> ans;
    while(curr_digit < max_digits){
        /* Add all digits in current position */
        int total = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i].length() > curr_digit){
                total += int(nums[i][curr_digit] - '0');
            }
        }

        /* Convert int total to string */
        std::stringstream ss2;
        ss2 << total;
        std::string totalstr = ss2.str();

        /* Store digit at current position from the total sum */
        ans.insert(ans.begin(), totalstr[totalstr.length() - 1]);

        /* Append carry over values */
        totalstr.append(curr_digit, '0');
        totalstr = reverse(totalstr);
        nums.push_back(totalstr);

        /* Check if there is a new longest integer */
        if(totalstr.length() > max_digits){
            max_digits = totalstr.length();
        }

        curr_digit++;
    }

    return ans;
}

/* Multiplies a large value x with value y; Vector stores the digits of x */
std::vector<int> multiply(std::vector<int> x, int y){
    std::vector<char> charans;
    std::vector<int> ans;
    std::vector<std::string> nums;
    int max_digits = 0;
    /* Multiply each digit of x with y */
    for(int i = 0; i < x.size(); i++){
        std::string prod = std::to_string(x[x.size() - i - 1] * y);
        for(int j = 0; j < i; j++){
            prod += '0';
        }
        if(prod.length() > max_digits){
            max_digits = prod.length();
        }
        prod = reverse(prod);
        nums.push_back(prod);
    }
    /* Add all of the products */
    charans = add(nums, max_digits);
    for(int i = 0; i < charans.size(); i++){
        ans.push_back(int(charans[i] - '0'));
    }
    
    /* Ans vector stores digits of the final product between x and y */
    return ans;
}

int main(){
    std::vector<int> fac;
    fac.push_back(1);
    for(int i = NUM; i > 0; i--){
        fac = multiply(fac, i);
    }

    int ans = 0;
    for(int i = 0; i < fac.size(); i++){
        ans += fac[i];
    }

    std::cout << ans << std::endl;

    return 0;
}
