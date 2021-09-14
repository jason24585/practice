#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

std::string NUMS[] = 
{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", 
"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", 
"eighteen", "nineteen"};

std::string TENS[] = 
{"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

std::string OTHERS[] = 
{"hundred", "thousand"};

/* Converts integer to written word */
std::string num_to_word(int num){
    std::stringstream ss;
    ss << num;
    std::string str = ss.str();
    std::string word;

    /* Thousands */
    if(str.length() >= 4){
        word += NUMS[std::stoi(str.substr(0, 1))] + " " + OTHERS[1];
        if(std::stoi(str.substr(1)) == 0){
            return word;
        }
        word += " ";
        str = str.substr(1);
    }

    /* Hundreds */
    if(str.length() >= 3){
        word += NUMS[std::stoi(str.substr(0, 1))] + " " + OTHERS[0];
        if(std::stoi(str.substr(1)) == 0){
            return word;
        }
        word += " and ";
        str = str.substr(1);
    }

    /* Tens */
    if(str.length() >= 2){
        if(str[0] == '1'){
            word += NUMS[std::stoi(str)];
            return word;
        }
        else if(str[0] != '0'){
            word += TENS[std::stoi(str.substr(0, 1))];
            if(std::stoi(str.substr(1)) == 0){
                return word;
            }
            word += " ";
        }
        str = str.substr(1);
    }

    /* Ones */
    if(str.length() >= 1){
        if(str[0] != '0'){
            word += NUMS[std::stoi(str)];
        }
    }

    return word;
}

int main(){
    int MAX_NUM = 1000;

    if(MAX_NUM > 9999 || MAX_NUM < 0){
        return 1;
    }

    int ans = 0;
    for(int i = 1; i <= MAX_NUM; i++){
        std::string str = num_to_word(i);
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        ans += str.length();
    }

    std::cout << ans << std::endl;

    return 0;
}
