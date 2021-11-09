#include <iostream>
#include <string>

/* Reverse a string */
std::string reverse(std::string input){
    for(int i = 0; i < input.length()/2; i++){
        char temp = input[input.length() - i - 1];
        input[input.length() - i - 1] = input[i];
        input[i] = temp;
    }

    return input;
}

/* Add two integers represented as strings */
std::string largesum(std::string x, std::string y){
    /* Digits in longest integer being added */
    int max_digits;
    max_digits = std::max(x.length(), y.length());

    /* Reverses both numbers to start adding from the back */
    x = reverse(x);
    y = reverse(y);

    /* Position of digits being added */
    int curr_digit = 0;

    std::string sum = "";
    int carry = 0;
    while(curr_digit < max_digits){
        /* Add digits in current position */
        int total = 0;
        if(x.length() > curr_digit){
            total += int(x[curr_digit] - '0');
        }
        if(y.length() > curr_digit){
            total += int(y[curr_digit] - '0');
        }
        total += carry;

        /* Convert int total to string */
        std::string totalstr = std::to_string(total);
        
        /* Store ones digit from total in sum */
        sum += totalstr[totalstr.length() - 1];

        /* Check if need to carry */
        if(totalstr.length() > 1){
            carry = 1;
        }
        else{
            carry = 0;
        }

        /* Add next digits */
        curr_digit++;
    }
    /* Add last carry */
    if(carry == 1){
        sum += std::to_string(carry);
    }

    return reverse(sum);
}

int main(){
    std::string x = "1";
    std::string y = "1";
    int ans = 2;
    while(y.length() < 1000){
        ans++;
        std::string temp = largesum(x, y);
        x = y;
        y = temp;
    }

    std::cout << ans << std::endl;

    return 0;
}
