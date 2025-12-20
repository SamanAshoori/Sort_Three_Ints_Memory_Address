//Hangman
#include <iostream> //for character input and output
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>

std::string selectRandomWord();
std::vector<int> guessLetter(std::string word, char input);
std::string makeDisplayWord(std::string word);
void revealLetters(std::vector<int>& inputVector , std::string& displayWord , char guess);

int main(){
    int lives = 13;
    int guesses = 0;
    std::vector<int> guessVector;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    //std::string word = selectRandomWord(); - hidden for testing
    std::string word = "test";
    std::string displayWord = makeDisplayWord(word);

    //char guess;
    //std::cout << "Please enter a guess" << '\n';
    //std::cin >> guess;

    guessVector = guessLetter(word,'t');

    for (int i : guessVector) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    revealLetters(guessVector, displayWord ,'t');

    //std::cout << word << '\n';
    //std::cout << displayWord << '\n';
    

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

std::vector<int> guessLetter(std::string word, char input){
    //guessLetter will tell us how many times each the input char appears in the string
    std::vector<int> output;
    input = std::tolower(input);
    int n = word.length();
    for (int i = 0; i < n; i++){
        if (input == word[i]){
            output.push_back(i);
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

void revealLetters(const std::vector<int>& inputVector , std::string& displayWord , char guess){
    for (int i: inputVector){
        displayWord[i] = guess;
    }

}