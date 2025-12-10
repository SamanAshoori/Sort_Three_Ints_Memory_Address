//Hangman
#include <iostream> //for character input and output
#include <cstdlib>
#include <string>
#include <ctime>

std::string selectRandomWord();

int main(){
    std::cout << selectRandomWord();
}

std::string selectRandomWord(){
    

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int max = 10;
    int min = 1;
    int range = max - min + 1;

    int randomNum = rand() % range + min;
    
    std::string words[10] = {
        "programmer",
        "language",
        "python",
        "string",
        "programming",
        "cascade",
        "electromagnetic",
        "whisper",
        "vortex",
        "luminance"
    };
    std::string word = words[randomNum];


    return word;
}