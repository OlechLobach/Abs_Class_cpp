#include "HomePet.h"
#include <iostream>

namespace HomePets {

    Characteristics::Characteristics(double val, const string& u) : value(val), unit(u) {}

    void Characteristics::display() const {
        cout << "Value: " << value << " " << unit << "\n";
    }

    HomePet::HomePet(const string& petName, int petAge, const Characteristics& petHeight, const Characteristics& petWeight, const string& petBreed, const std::string& petCharacter)
        : name(petName), age(petAge), height(petHeight), weight(petWeight), breed(petBreed), character(petCharacter) {}

    void HomePet::show() const {
        cout << "Name: " << name << "\n";
        cout << "Height: ";
        height.display();
        cout << "Weight: ";
        weight.display();
        cout << "Age: " << age << "\n";
        cout << "Breed: " << breed << "\n";
        cout << "Character: " << character << "\n";
    }

    HomePet::~HomePet() {}

    Dog::Dog(const string& dogName, int dogAge, const Characteristics& dogHeight, const Characteristics& dogWeight, const string& dogBreed, const string& dogCharacter)
        : HomePet(dogName, dogAge, dogHeight, dogWeight, dogBreed, dogCharacter) {}

    void Dog::sound() const {
        cout << "Woof! Woof!\n";
    }

    void Dog::type() const {
        cout << "Type: Dog\n";
    }

    Cat::Cat(const string& catName, int catAge, const Characteristics& catHeight, const Characteristics& catWeight, const string& catBreed, const string& catCharacter)
        : HomePet(catName, catAge, catHeight, catWeight, catBreed, catCharacter) {}

    void Cat::sound() const {
        cout << "Meow!\n";
    }

    void Cat::type() const {
        cout << "Type: Cat\n";
    }

    Parrot::Parrot(const string& parrotName, int parrotAge, const Characteristics& parrotWingspan)
        : HomePet(parrotName, parrotAge, Characteristics(0, ""), Characteristics(0, ""), "", ""), wingspan(parrotWingspan) {}

    void Parrot::sound() const {
        cout << "Squawk! Squawk!\n";
    }

    void Parrot::type() const {
        cout << "Type: Parrot\n";
    }

    Hamster::Hamster(const string& hamsterName, int hamsterAge, const Characteristics& hamsterWheelSize)
        : HomePet(hamsterName, hamsterAge, Characteristics(0, ""), Characteristics(0, ""), "", ""), wheelSize(hamsterWheelSize) {}

    void Hamster::sound() const {
        cout << "Squeak! Squeak!\n";
    }

    void Hamster::type() const {
        cout << "Type: Hamster\n";
    }

}