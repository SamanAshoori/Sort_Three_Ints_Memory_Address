//Option 1: Text-Based RPG Battle (The "Class" Project)
//The Concept: Object-Oriented Programming (Classes & Objects). Why: In Hangman, you had lives and guesses floating around in main. In a real C++ program, you want to bundle data and behavior together.
//The Project: Create a simple 1v1 battle simulator (like Pokémon or Final Fantasy). You need a Player and an Enemy. They take turns attacking until one dies.
//New Things You Will Learn:
//Classes: Creating a class Character.
//Encapsulation: keeping health private and only changing it via a public function takeDamage(int amount).
//Constructors: Setting up the character's name and max health when the object is created.
//RNG: Better random number generation for damage variance (e.g., hitting for 5-10 damage).
//Spicy Twist (For the brave): Implement Inheritance. Make a base class Entity, then have Player and Goblin inherit from it.

//Above Prompt is prompt when asked where can I go from hangman to improve c++

#include <string>

class Entity {
    public:
        Entity(std::string input){
            name = input;
        }

        void takeDamage(int damage){
            health -= damage;
        }

        void setName(std::string input){
            name = input;

        }
        void setMaxHealth(int input){
            max_health = input;
        }

    private:
        int health;
        int max_health;
        std::string name;

};

class Player : public Entity{

};


int main(){

    Entity testEntity;

    testEntity.setMaxHealth(10);
    testEntity.setName("Test");
    return 0;
}
