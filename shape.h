#ifndef SHAPE_H
#define SAPE_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
namespace Shapes {
    class Shape {
    public:
        virtual void Show() const = 0;
        virtual void Save(const string& filename) const = 0;
        virtual void Load(const string& filename) = 0;
        virtual ~Shape() {}
    };

    class Rectangle : public Shape {
    private:
        int x, y; 
        int width, height; 
    public:
        Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

        void Show() const override {
            cout << "Rectangle: Top-left corner at (" << x << ", " << y << "), Width: " << width << ", Height: " << height << endl;
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                        cout << "* ";
                    }
                    else {
                        cout << "  ";
                    }
                }
                cout << endl;
            }
            cout << endl;
        }

        void Save(const string& filename) const override {
            ofstream file(filename);
            file << "Rectangle " << x << " " << y << " " << width << " " << height;
            file.close();
        }

        void Load(const string& filename) override {
            ifstream file(filename);
            if (file.is_open()) {
                string shapeType;
                file >> shapeType >> x >> y >> width >> height;
                file.close();
            }
        }
    };

    class Circle : public Shape {
    private:
        int centerX, centerY; 
        int radius; 
    public:
        Circle(int centerX, int centerY, int radius) : centerX(centerX), centerY(centerY), radius(radius) {}

        void Show() const override {
            cout << "Circle: Center at (" << centerX << ", " << centerY << "), Radius: " << radius << endl;
            for (int i = -radius; i <= radius; ++i) {
                for (int j = -radius; j <= radius; ++j) {
                    if (i * i + j * j <= radius * radius) {
                        cout << "* ";
                    }
                    else {
                        cout << "  ";
                    }
                }
                cout << endl;
            }
            cout << endl;
        }

        void Save(const string& filename) const override {
            ofstream file(filename);
            file << "Circle " << centerX << " " << centerY << " " << radius;
            file.close();
        }

        void Load(const string& filename) override {
            ifstream file(filename);
            if (file.is_open()) {
                string shapeType;
                file >> shapeType >> centerX >> centerY >> radius;
                file.close();
            }
        }
    };

    class Ellipse : public Shape {
    private:
        int x, y; 
        int majorAxis, minorAxis; 
    public:
        Ellipse(int x, int y, int majorAxis, int minorAxis) : x(x), y(y), majorAxis(majorAxis), minorAxis(minorAxis) {}

        void Show() const override {
            cout << "Ellipse: Top corner at (" << x << ", " << y << "), Major Axis: " << majorAxis << ", Minor Axis: " << minorAxis << endl;
            for (int i = 0; i < 2 * minorAxis; ++i) {
                for (int j = 0; j < majorAxis; ++j) {
                    if ((((i - minorAxis) * (i - minorAxis) * majorAxis * majorAxis) +
                        ((j - majorAxis / 2) * (j - majorAxis / 2) * minorAxis * minorAxis))
                        <= (majorAxis * minorAxis * minorAxis * minorAxis)) {
                        cout << "* ";
                    }
                    else {
                        cout << "  ";
                    }
                }
                cout << endl;
            }
            cout << endl;
        }

        void Save(const string& filename) const override {
            ofstream file(filename);
            file << "Ellipse " << x << " " << y << " " << majorAxis << " " << minorAxis;
            file.close();
        }

        void Load(const string& filename) override {
            ifstream file(filename);
            if (file.is_open()) {
                string shapeType;
                file >> shapeType >> x >> y >> majorAxis >> minorAxis;
                file.close();
            }
        }
    };
} 
#endif 