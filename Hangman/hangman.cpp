//Hangman
#include <iostream> //for character input and output
#include <cstdlib>
#include <string>
#include <ctime>

std::string selectRandomWord();

int main(){
    std::string word = selectRandomWord();
    //std::cout << word; - dont need it for now as we know it works

    std::string guess;
    std::cin >> guess;
    std::cout << guess;

}

std::string selectRandomWord(){
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
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

    // Auto-calculate size
    int size = sizeof(words) / sizeof(words[0]);
    
    // Generates 0 to 9 safely
    int randomNum = std::rand() % size;
    std::string word = words[randomNum];

    return word;
}

bool guessLetter(std::string word, char input){
    //example outputfor now
    return true

}