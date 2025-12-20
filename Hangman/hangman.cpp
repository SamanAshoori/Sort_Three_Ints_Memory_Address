//Hangman
#include <iostream> //for character input and output
#include <cstdlib>
#include <string>
#include <ctime>

std::string selectRandomWord();
int guessLetter(std::string word, char input);
std::string makeDisplayWord(std::string word);

int main(){
    int lives = 13;
    int guesses = 0;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    //std::string word = selectRandomWord(); - hidden for testing
    std::string word = "test";
    std::string displayWord = makeDisplayWord(word);

    //char guess;
    //std::cout << "Please enter a guess" << '\n';
    //std::cin >> guess;

    //std::cout << guessLetter(word,guess);
    std::cout << word << '\n';
    std::cout << displayWord << '\n';
    

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

int guessLetter(std::string word, char input){
    //guessLetter will tell us how many times each the input char appears in the string
    int output = 0;
    input = std::tolower(input);
    int n = word.length();
    for (int i = 0; i < n; i++){
        if (input == word[i]){
            output++;
        }
    }
    return output;
}

std::string makeDisplayWord(std::string word){
    for (int j = 0; j < word.length() ; j++){
        word[j] = '_';
    }
    return word;

}

//char revealLetter