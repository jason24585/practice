#include <iostream>

enum Day {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, DaysInWeek};

enum Month {January, February, March, April, May, June, July, August, September, October, November, December};

#define startYear 1901
#define endYear 2000
#define startMonth January
#define endMonth December
#define startDay Tuesday /* Day on start date (January 1, 1901) */

/* Return days in specific month, year */
int daysM(int month, int year){
    switch(month){
        case February:
            /* Leap years */
            if(year % 4 == 0){
                if(year % 100 != 0){
                    return 29;
                }
                else if(year % 400 == 0){
                    return 29;
                }
            }
            return 28;
        case April:
        case June:
        case September:
        case November:
            return 30;
        default:
            return 31;
    }
}

int main(){
    int ans = 0;
    /* First day of month */
    int start = startDay;
    for(int i = startYear; i <= endYear; i++){
        for(int j = startMonth; j <= endMonth; j++){
            if(start == Sunday){
                ans++;
            }
            start = (start + (daysM(i, j) % DaysInWeek)) % DaysInWeek;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
