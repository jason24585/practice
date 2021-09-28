#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

int main(){
    std::ifstream file("names.txt");

    std::string name;
    std::vector<std::string> names;
    /* Parse names using ',' and remove '"' */
    while(std::getline(file, name, ',')){
        name.erase(std::remove(name.begin(), name.end(), '"'), name.end());
        names.push_back(name);
    }
    /* Sort names alphabetically */
    std::sort(names.begin(), names.end());

    int ans = 0;
    int position = 1;
    /* Multiply alphabetical value with alphabetical position to get name score */
    for(int i = 0; i < names.size(); i++){
        name = names[i];
        int sum = 0;
        for(int i = 0; i < name.length(); i++){
            sum += int(name[i]) - 64;
        }
        ans += sum * position;
        position++;
    }

    std::cout << ans << std::endl;

    return 0;
}
