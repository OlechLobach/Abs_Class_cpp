#include"shape.h"
int main() {
    using namespace Shapes;

    vector<Shape*> shapes;

    int choice;
    do {
        cout << "Choose a shape to display:\n"
            << "1. Rectangle\n"
            << "2. Circle\n"
            << "3. Ellipse\n"
            << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            shapes.push_back(new Rectangle(0, 0, 5, 3));
            shapes.back()->Show();  
            break;
        case 2:
            shapes.push_back(new Circle(2, 2, 4));
            shapes.back()->Show();  
            break;
        case 3:
            shapes.push_back(new Ellipse(1, 1, 6, 3));
            shapes.back()->Show(); 
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

   
    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}