#include "HomePet.h"

using namespace HomePets;


int main() {
    std::string name, breed, character;
    int age;
    Characteristics height, weight;

    
    cout << "Enter the name of the dog: ";
    getline(cin, name);

    cout << "Enter the age of the dog: ";
    cin >> age;

    cout << "Enter the height of the dog (in cm): ";
    cin >> height.value;
    height.unit = "cm";

    cout << "Enter the weight of the dog (in kg): ";
    cin >> weight.value;
    weight.unit = "kg";

    cout << "Enter the breed of the dog: ";
    cin.ignore();
    getline(cin, breed);

    cout << "Enter the character of the dog: ";
    getline(cin, character);

    Dog myDog(name, age, height, weight, breed, character);

    cout << "\n--- Information about the dog ---\n";
    myDog.show();
    myDog.sound();
    myDog.type();
    cout << "\n";


    cout << "Enter the name of the cat: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter the age of the cat: ";
    cin >> age;

    Cat myCat(name, age, height, weight, breed, character);

    cout << "\n--- Information about the cat ---\n";
    myCat.show();
    myCat.sound();
    myCat.type();
    cout << "\n";


    cout << "Enter the name of the parrot: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter the age of the parrot: ";
    cin >> age;

    Characteristics parrotWingspan;
    cout << "Enter the wingspan of the parrot (in cm): ";
    cin >> parrotWingspan.value;
    parrotWingspan.unit = "cm";

    Parrot myParrot(name, age, parrotWingspan);

    cout << "\n--- Information about the parrot ---\n";
    myParrot.show();
    myParrot.sound();
    myParrot.type();
    cout << "\n";

  
    Hamster myHamster(name, age, weight);  
    cout << "\n--- Information about the hamster ---\n";
    myHamster.show();
    myHamster.sound();
    myHamster.type();
    cout << "\n";


    return 0;
}