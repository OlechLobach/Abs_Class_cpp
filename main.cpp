#include"abstract.h"

int main() {
   
    using namespace Lists;

    List* myList = nullptr;

    cout << "Enter 0 for Stack, 1 for Queue: ";
    int choice;
    cin >> choice;

    switch (choice) {
    case 0:
        myList = new Stack();
        break;
    case 1:
        myList = new Queue();
        break;
    default:
        cerr << "Invalid choice. Exiting program.\n";
        return 1;
    }

    myList->insert(10);
    myList->insert(20);
    myList->insert(30);

    cout << "Removed: " << myList->remove() << endl;
    cout << "Removed: " << myList->remove() << endl;

    delete myList;

    return 0;
}
