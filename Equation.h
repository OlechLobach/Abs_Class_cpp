#ifndef EQUATION_H
#define EQUATION_H

#include <iostream>
#include <cmath>
using namespace std;
namespace EquationSolver {

    class Equation {
    public:
        virtual void solve() const = 0;
        virtual ~Equation() = default;
    };

    class LinearEquation : public Equation {
    private:
        double a, b;

    public:
        LinearEquation(double coeffA, double coeffB);

        void solve() const override;
    };

    class QuadraticEquation : public Equation {
    private:
        double a, b, c;

    public:
        QuadraticEquation(double coeffA, double coeffB, double coeffC);

        void solve() const override;
    };

}

#endif