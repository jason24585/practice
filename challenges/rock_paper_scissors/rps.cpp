#include <iostream>
#include <algorithm>
#include <random>
#include <limits>

/* Choices */
enum choices{
    rock,
    paper,
    scissors,
    NUM_CHOICES = 3
};

std::string strChoices(int choice){
    switch(choice){
        case choices::rock:
            return "rock";
        case choices::paper:
            return "paper";
        case choices::scissors:
            return "scissors";
    }
    return "error";
}

/* Results */
enum results{
    lose,
    win,
    tie,
    NUM_RESULTS = 3
};

std::string strResults(int result){
    switch(result){
        case results::lose:
            return "lose. :(";
        case results::win:
            return "win. :)";
        case results::tie:
            return "tied. :|";
    }
    return "error";
}

/* Game class */
class rps{
    private:
        /* Store choices made and result calculated */
        int player = -1;
        int opponent = -1;
        int result = -1;

        /* Vector to store matchups between choices */
        std::vector<int> rules = {
            /* 0 - rock */
            {choices::paper},
            /* 1 - paper */
            {choices::scissors},
            /* 2 - scissors */
            {choices::rock}
        };

    public:
        void setPlayer(int choice){
            player = choice;
        }

        void setOpponent(int choice){
            opponent = choice;
        }

        int getPlayer(){
            return player;
        }

        int getOpponent(){
            return opponent;
        }

        /* Calculate result */
        void setResult(){
            if(player == -1 || opponent == -1){
                std::cerr << "Choices not set." << std::endl;
            }
            if(player == opponent){
                result = results::tie;
            }
            else{
                result = std::find(rules.begin(), rules.end(), opponent) == rules.end();
            }
        }

        int getResult(){
            return result;
        }
};

int main(){
    /* Print title */
    std::cout << "*** Rock, Paper, Scissors ***" << std::endl << std::endl;

    /* Get user input */
    int input;
    std::cout << "Rock, paper, scissors, shoot! (rock[0]/paper[1]/scissors[2]): " << std::endl;
    while(!(std::cin >> input) || input < 0 || input >= choices::NUM_CHOICES){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Invalid input(rock[0]/paper[1]/scissors[2]), try again: " << std::endl;
    }

    /* Generate random value */
    std::random_device r;
    std::mt19937 rng(r());
    std::uniform_int_distribution<int> distribute(0, choices::NUM_CHOICES - 1);
    int random = distribute(rng);

    /* Setup game */
    rps game;
    game.setPlayer(input);
    game.setOpponent(random);
    game.setResult();

    /* Print results */
    std::cout << "You chose " << strChoices(game.getPlayer()) << "." << std::endl;
    std::cout << "I chose " << strChoices(game.getOpponent()) << "." << std::endl;
    std::cout << "You " << strResults(game.getResult()) << std::endl;

    return 0;
}
