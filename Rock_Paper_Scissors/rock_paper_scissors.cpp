#include <iostream> //for character input and output
#include <random>

int main()
{
    int max = 3;
    int min = 1;

    std::cout << "Welcome to Rock Paper Scissors - Please 1 for Rock , 2 for Paper and 3 for Scissors: ";
    int x{}; //defining variable to hold user input

    std::cin >> x; //get number from user
    int range = max - min + 1;
    int computerChoice = rand() % range + min;

    std::cout << "You entered: " << x << '\n';
    std::cout << "Computer entered: " << computerChoice << '\n';

}