#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

int main(){
    int ROWS = 15;

    std::string NUMS = 
    "75 "
    "95 64 "
    "17 47 82 "
    "18 35 87 10 "
    "20 04 82 47 65 "
    "19 01 23 75 03 34 "
    "88 02 77 73 07 63 67 "
    "99 65 04 28 06 16 70 92 "
    "41 41 26 56 83 40 80 70 33 "
    "41 48 72 33 47 32 37 16 94 29 "
    "53 71 44 65 25 43 91 52 97 51 14 "
    "70 11 33 28 77 73 17 78 39 68 17 57 "
    "91 71 52 38 17 14 91 43 58 50 27 29 48 "
    "63 66 04 68 89 53 67 30 73 16 69 87 40 31 "
    "04 62 98 27 23 09 70 98 73 93 38 53 60 04 23 ";
    
    std::stringstream ss;
    ss << NUMS;

    /* Initialize triangle vectors, tracking initial values and total sums */
    std::vector<std::vector<int>> array;
    std::vector<std::vector<int>> sumarray;
    int temp;
    for(int i = 0; i < ROWS; i++){
        std::vector<int> row;
        std::vector<int> sumrow;
        for(int j = 0; j <= i; j++){
            ss >> temp;
            row.push_back(temp);
            sumrow.push_back(0);
        }
        array.push_back(row);
        sumarray.push_back(sumrow);
    }
    sumarray[0][0] = array[0][0];

    /* Calculate maximum sums for each route */
    for(int i = 0; i < ROWS - 1; i++){
        for(int j = 0; j <= i; j++){
            int sum1 = sumarray[i][j] + array[i + 1][j];
            if(sum1 > sumarray[i + 1][j]){
                sumarray[i + 1][j] = sum1;
            }
            int sum2 = sumarray[i][j] + array[i + 1][j + 1];
            if(sum2 > sumarray[i + 1][j + 1]){
                sumarray[i + 1][j + 1] = sum2;
            }
        }
    }
    
    /* Get maximum total */
    int ans = *std::max_element(sumarray[ROWS - 1].begin(), sumarray[ROWS - 1].end());

    std::cout << ans << std::endl;

    return 0;
}
