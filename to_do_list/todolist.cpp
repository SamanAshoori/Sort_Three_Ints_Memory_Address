//God Damn it here I go do doing babys first coding app.
#include <iostream>
#include <fstream>

void writeFile(std::string input);

//main.cpp
int main(){
    writeFile("Hello World! + Saman + Build Test + New Line") ;
    std::cout << "File Created" << '\n';

    std::ifstream inputFile("test1.txt");
    if(!inputFile){
        std::cerr << "Error opening file" << '\n';
        return 1; // Return an error code if the file cannot be opened
    }

    std::string word;
    while (inputFile >> word) {
        std::cout << word << '\n'; // Output each word on a new line
    }
    inputFile.close();
    return 0;
}

void writeFile(std::string input){
    std::ofstream test("test.txt");
    test << input;
    test.close();
}