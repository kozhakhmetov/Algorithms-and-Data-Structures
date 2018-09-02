
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

class MyQueue {
public:
    Node* head;
    Node* tail;
    int _size = 0;

    MyQueue () {
        head = NULL;
        tail = NULL;
    }

    void push(int val) {
        Node* temp = new Node(val);
        if (_size == 0) {
            head = temp;
            tail = temp;
        }else {
            head->prev = temp;
            temp->next = head;
            head = temp;
        }
        _size++;
    }

    int front() {
      return tail->data;
    }

    int pop() {
        int val = tail->data;
        if (tail->prev != NULL)
            tail = tail->prev;
        tail->next = nullptr;
        _size--;
        return val;
    }

    void clear() {
        head = NULL;
        tail = NULL;
        _size = 0;
    }

    bool empty() {
        return _size == 0;
    }

    int size() {
        return _size;
    }

};

int main () {

}