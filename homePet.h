#ifndef HOMEPET_H
#define HOMEPET_H

#include <iostream>
#include <string>
using namespace std;
namespace HomePets {

    class Characteristics {
    public:
        double value;  
        string unit;

        Characteristics() : value(0), unit("") {}
        Characteristics(double val, const string& u);

        void display() const;  
    };

    class HomePet {
    protected:
        string name;
        int age;
        Characteristics height;
        Characteristics weight;
        string breed;
        string character;

    public:
        HomePet(const string& petName, int petAge, const Characteristics& petHeight, const Characteristics& petWeight, const string& petBreed, const string& petCharacter);
        virtual void sound() const = 0;
        void show() const;
        virtual void type() const = 0;

        virtual ~HomePet();
    };

    class Dog : public HomePet {
    public:
        Dog(const string& dogName, int dogAge, const Characteristics& dogHeight, const Characteristics& dogWeight, const string& dogBreed, const string& dogCharacter);
        void sound() const override;
        void type() const override;
    };

    class Cat : public HomePet {
    public:
        Cat(const string& catName, int catAge, const Characteristics& catHeight, const Characteristics& catWeight, const string& catBreed, const string& catCharacter);
        void sound() const override;
        void type() const override;
    };

    class Parrot : public HomePet {
    private:
        Characteristics wingspan;

    public:
        Parrot(const string& parrotName, int parrotAge, const Characteristics& parrotWingspan);
        void sound() const override;
        void type() const override;
    };

    class Hamster : public HomePet {
    private:
        Characteristics wheelSize;

    public:
        Hamster(const string& hamsterName, int hamsterAge, const Characteristics& hamsterWheelSize);
        void sound() const override;
        void type() const override;
    };

} 

#endif