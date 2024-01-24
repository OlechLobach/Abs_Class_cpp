#include "Equation.h"
#include <iostream>
#include <limits>

int main() {
    using namespace EquationSolver;

    double a, b, c;
    char equationType;

    cout << "Enter the coefficients of the equation:\n";
    cout << "a: ";
    cin >> a;

    cout << "b: ";
    cin >> b;

    cout << "c: ";
    cin >> c;

    cout << "Choose equation type (L for Linear, Q for Quadratic): ";
    cin >> equationType;

    if (cin.fail()) {
        cerr << "Invalid input. Please enter valid numbers.\n";
        return 1;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Equation* equation;

    if (equationType == 'L' || equationType == 'l') {
        equation = new LinearEquation(a, b);
    }
    else if (equationType == 'Q' || equationType == 'q') {
        equation = new QuadraticEquation(a, b, c);
    }
    else {
        cout << "Invalid equation type.\n";
        return 1;
    }

    equation->solve();

    delete equation;

    return 0;
}