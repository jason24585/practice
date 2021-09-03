#include <iostream>
#include <time.h>
#include <limits>

/* TODO: Days are inaccurate; Not considering leap years, different days each months, etc. */
int days_in_month = 31;
int months_in_year = 12;
int seconds_in_day = 86400;

int main(){
    /* Print title */
    std::cout << "*** Age in Seconds ***" << std::endl << std::endl;

    /* Get current date */
    time_t t = time(NULL);
    struct tm *curr = localtime(&t);
    int curr_day = curr->tm_mday;
    int curr_month = curr->tm_mon + 1;
    int curr_year = curr->tm_year + 1900;

    /* Get user input */
    int day;
    int month;
    int year;
    while(true){
        std::cout << "Enter birthday [mm/dd/yyyy]: " << std::endl;
        std::cin >> month;
        if(std::cin.get() != '/' || month < 1 || month > months_in_year){
            std::cout << "Invalid month, try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin >> day;
        if(std::cin.get() != '/' || day < 1 || day > days_in_month){
            std::cout << "Invalid day, try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if(!(std::cin >> year) || year < 0 || year > curr_year){
            std::cout << "Invalid year, try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        /* Check if input date is greater than current date */
        if(year == curr_year){
            if(month >= curr_month){
                if(day > curr_day){
                    std::cout << "Invalid date, try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
            }
        }
        break;
    }

    /* Calculate difference in input date and current date */
    int day_diff;
    int month_diff;
    int year_diff = curr_year - year;
    if(month > curr_month){
        month_diff = (curr_month + months_in_year) - month;
    }
    else{
        month_diff = curr_month - month;
    }
    if(day > curr_day){
        day_diff = (curr_day + days_in_month) - day;
    }
    else{
        day_diff = curr_day - day;
    }

    /* Calculate and print seconds */
    month_diff += year_diff * months_in_year;
    day_diff += month_diff * days_in_month;
    int seconds = day_diff * seconds_in_day;

    std::cout << "Age in seconds: " << seconds << std::endl;

    return 0;
}
