//Hangman
#include <iostream> //for character input and output
#include <cstdlib>
#include <string>
#include <ctime>

std::string selectRandomWord();
bool guessLetter(std::string word, char input);
std::string makeDisplayWord(std::string word);

int main(){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    //std::string word = selectRandomWord(); - hidden for testing
    std::string word = "test";

    char guess;
    std::cout << "Please enter a guess" << '\n';
    std::cin >> guess;

    std::cout << guessLetter(word,guess);

}

std::string selectRandomWord(){
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

    input = std::tolower(input);
    int n = word.length();
    for (int i = 0; i < n; i++){
        if (input == word[i]){
            return true;
        }
    }
    return false; //if reached end of for loop and no true then it does not exist
}

std::string makeDisplayWord(std::string word){
    std::string displayWord;
    //To DO - Make code that gets length of word and changes all chars to "_" 
    return displayWord;

}