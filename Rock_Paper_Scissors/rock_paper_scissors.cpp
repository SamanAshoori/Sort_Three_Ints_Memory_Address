#include <iostream> //for character input and output
#include <cstdlib>
#include <unordered_map>
#include <string>
#include <ctime>
#include <vector> //for scoring

//Function Declaration
void displayFinalStats(std::vector <std::string> rounds, std::string winner, int gamesPlayed);

int main()
{
    //Seed Random Number
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    //set max and min for random number
    int max = 3;
    int min = 1;
    //set player and computer score
    int playerScore = 0;
    int computerScore = 0;
    int gamesPlayed = 0;
    std::vector <std::string> rounds;

    // Create an unordered_map
    std::unordered_map<int,std::string> umap;

    // Insert key-value pairs into the unordered_map
    umap[1] = "Rock";
    umap[2] = "Paper"; 
    umap[3] = "Scissors"; 

    while (playerScore != 3 && computerScore != 3 )
    {
        std::cout << "-------------------------------------------------------------------------------------------" << '\n';
        std::cout << "Welcome to Rock Paper Scissors - Please Enter 1 for Rock , 2 for Paper and 3 for Scissors: ";
        int x{}; //defining variable to hold user input

        std::cin >> x; //get number from user
        int range = max - min + 1;
        int computerChoice = rand() % range + min;

        std::cout << "You entered: " << umap[x] << '\n';
        std::cout << "Computer entered: " << umap[computerChoice] << '\n';

        //SADLY GOING TO IF STATEMENT MAX as my current knowledge of c++ is not advanced yet
        if(x == computerChoice)
        {
            std::cout << "Draw" << '\n';
            rounds.push_back("Draw");
        }
        //Will else if all player wins and any else is computer win
        //player rock and computer rock
        else if(x == 1 && computerChoice == 3)
        {
            std::cout << "You Win" << '\n';
            playerScore = playerScore + 1;
            rounds.push_back("Player Win");
        }
        //player paper and computer rock
        else if(x == 2 && computerChoice == 1)
        {
            std::cout << "You Win" << '\n';
            playerScore = playerScore + 1;
           rounds.push_back("Player Win");
        }
        //player scissors and computer paper
        else if(x == 3 && computerChoice == 2)
        {
            std::cout << "You Win" << '\n';
            playerScore = playerScore + 1;
            rounds.push_back("Player Win");
        }
        else
        {
        std::cout << "Computer Won" << '\n';
        computerScore = computerScore +1;
        rounds.push_back("Computer Win");
        }
        gamesPlayed = gamesPlayed + 1;
    }
    std::cout << "------------------------------------------------------------" << '\n';
    if(playerScore == 3) { displayFinalStats(rounds,"You",gamesPlayed);
    }
    else if (computerScore == 3) { displayFinalStats(rounds,"Computer",gamesPlayed);
    }
}

void displayFinalStats(std::vector <std::string> rounds, std::string winner, int gamesPlayed)
{
    std::cout << winner <<" Won!" << '\n';
        std::cout << "Games Played: " << gamesPlayed << '\n'; 
        std::cout << "----- Round History -----" << '\n';
        for (int i = 0; i < rounds.size(); i++) 
        {
            std::cout << "Round " << i+1 << ": " << rounds[i] << "\n";
        }
}
