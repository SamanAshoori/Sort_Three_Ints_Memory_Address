#include <iostream> //for character input and output
#include <cstdlib>
#include <unordered_map>
#include <string>
#include <ctime>

int main()
{
    //Seed Random Number
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    //set max and min for random number
    int max = 3;
    int min = 1;

    // Create an unordered_map
    std::unordered_map<int,std::string> umap;

    // Insert key-value pairs into the unordered_map
    umap[1] = "Rock";
    umap[2] = "Paper"; 
    umap[3] = "Scissors"; 

    std::cout << "Welcome to Rock Paper Scissors - Please 1 for Rock , 2 for Paper and 3 for Scissors: ";
    int x{}; //defining variable to hold user input

    std::cin >> x; //get number from user
    int range = max - min + 1;
    int computerChoice = rand() % range + min;

    std::cout << "You entered: " << umap[x] << '\n';
    std::cout << "Computer entered: " << umap[computerChoice] << '\n';

}