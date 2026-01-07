//God Damn it here I go do doing babys first coding app.
#include <iostream>
#include <fstream>

void writeFile(std::string input);

//main.cpp
int main(){
    writeFile("Hello World! + Saman");
    return 0;
}

void writeFile(std::string input){
    std::ofstream test("test.txt");
    test << input;
    test.close();
}