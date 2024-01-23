#ifndef ABSTRACT_H
#define ABSTRACT_H

#include <iostream>
using namespace std;

namespace Lists {

   
    class List {
    public:
        virtual void insert(int value) = 0;
        virtual int remove() = 0;
        virtual ~List() {}
    };

  
    class Stack : public List {
    private:
        class Node {
        public:
            int data;
            Node* next;

            Node(int value) : data(value), next(nullptr) {}
        };

        Node* top;

    public:
        Stack() : top(nullptr) {}

        void insert(int value) override {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
        }

        int remove() override {
            if (isEmpty()) {
                cerr << "Stack is empty. Cannot remove element.\n";
                return -1;
            }

            int removedValue = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;

            return removedValue;
        }

        bool isEmpty() const {
            return top == nullptr;
        }

        ~Stack() {
            while (!isEmpty()) {
                remove();
            }
        }
    };


    class Queue : public List {
    private:
        class Node {
        public:
            int data;
            Node* next;

            Node(int value) : data(value), next(nullptr) {}
        };

        Node* front;
        Node* rear;

    public:
        Queue() : front(nullptr), rear(nullptr) {}

        void insert(int value) override {
            Node* newNode = new Node(value);
            if (isEmpty()) {
                front = rear = newNode;
            }
            else {
                rear->next = newNode;
                rear = newNode;
            }
        }

        int remove() override {
            if (isEmpty()) {
                cerr << "Queue is empty. Cannot remove element.\n";
                return -1;
            }

            int removedValue = front->data;
            Node* temp = front;
            front = front->next;

            if (front == nullptr) {
                rear = nullptr;
            }

            delete temp;

            return removedValue;
        }

        bool isEmpty() const {
            return front == nullptr;
        }

        ~Queue() {
            while (!isEmpty()) {
                remove();
            }
        }
    };
}

#endif 