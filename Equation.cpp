#include "Equation.h"


namespace EquationSolver {

    LinearEquation::LinearEquation(double coeffA, double coeffB) : a(coeffA), b(coeffB) {}

    void LinearEquation::solve() const {
        if (a == 0) {
            cout << "Not a linear equation.\n";
        }
        else {
            double root = -b / a;
            cout << "Linear equation root: " << root << "\n";
        }
    }

    QuadraticEquation::QuadraticEquation(double coeffA, double coeffB, double coeffC) : a(coeffA), b(coeffB), c(coeffC) {}

    void QuadraticEquation::solve() const {
        if (a == 0) {
            cout << "Not a quadratic equation.\n";
        }
        else {
            double discriminant = b * b - 4 * a * c;
            if (discriminant > 0) {
                double root1 = (-b + sqrt(discriminant)) / (2 * a);
                double root2 = (-b - sqrt(discriminant)) / (2 * a);
                cout << "Quadratic equation roots: " << root1 << " and " << root2 << "\n";
            }
            else if (discriminant == 0) {
                double root = -b / (2 * a);
                cout << "Quadratic equation has a repeated root: " << root << "\n";
            }
            else {
                cout << "Quadratic equation has complex roots.\n";
            }
        }
    }

}