#include <iostream>

using namespace std;

class Node {
public:
    Node* next = (NULL);
    Node* prev = (NULL);
    int data;

    Node (int _data = 0) {
        data = _data;
    }
};

class MyStack {
public:
    Node* tail;
    int _size = 0;
    MyStack () {
        tail = new Node();
    }

    int size() {
        return _size;
    }

    void push (int val) {
        Node* temp = new Node(val);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        _size++;
    }

    int top() {
        return tail->data;
    }

    int pop() {
        int val = tail->data;
        tail = tail->prev;
        tail->next = NULL;
        _size--;
        return val;
    }

    void clear () {
        tail = new Node();
        _size = 0;
    }

};

int main() {
}