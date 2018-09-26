
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node {
public:
    Node* next;
    Node* prev;
    T data;

    Node (T _data = 0) {
        data = _data;
        next = nullptr;
        prev = nullptr;
    }

};

template <typename T>
class MyQueue {
public:
    Node<T>* head;
    Node<T>* tail;
    int _size;

    MyQueue () {
        _size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void push(T val) {
        Node<T>* temp = new Node<T>(val);
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

    T front() {
      return tail->data;
    }

    T pop() {
        T val = tail->data;
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