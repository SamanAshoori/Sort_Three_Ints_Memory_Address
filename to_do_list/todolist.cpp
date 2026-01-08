//God Damn it here I go do doing babys first coding app.
#include <iostream>
#include <fstream>

void writeFile(std::string input);

//main.cpp
int main(){
    writeFile("Hello World! + Saman + Build Test + New Line") ;
    std::cout << "File Created" << '\n';

    std::ifstream inputFile("test.txt");
    if(!inputFile){
        std::cerr << "Error opening file" << '\n';
    }
    return 0;
}

void writeFile(std::string input){
    std::ofstream test("test.txt");
    test << input;
    test.close();
}