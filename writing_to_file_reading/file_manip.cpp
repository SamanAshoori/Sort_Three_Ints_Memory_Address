#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime> // Required for time_t


//main.cpp
void writeFile(std::string input); // Function Prototype

int main(){
    // Create the test file first
    writeFile("Hello World! + Saman + Build Test + New Line") ;
    std::cout << "File Created" << std::endl; // Used std::endl to force print

    std::ifstream inputFile("test.txt");
    if(!inputFile){
        std::cerr << "Error opening file" << std::endl;
        return 1; 
    }

    std::string word;
    while (inputFile >> word) {
        std::cout << word << '\n'; 
    }
    inputFile.close();


}

void writeFile(std::string input){
    std::ofstream test("test.txt");
    test << input;
    test.close();
}