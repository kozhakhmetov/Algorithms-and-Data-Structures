#include <iostream>

using namespace std;

template <typename T>
class Node {

public:
    Node* next;
    Node* prev;
    T data;

    Node (T _data = 0) {
        data = _data;
        next = (nullptr);
        prev = (nullptr);
    }
};

template <typename T>
class LinkedList {

public:
    Node<T>* head;
    Node<T>* tail;
    int _size;

    LinkedList () {
        head = new Node<T>(NULL);
        tail = head;
        _size = 0;
    }

    void add(T val) {
        Node<T>* temp = new Node<T>(val);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        _size++;
    }

    bool empty() {
        return (_size == 0);
    }

    void remove_ith(int id) {
        if (id > _size) {
            return;
        }
        Node<T>* cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
            if (--id == 0) {
                if (cur->next != NULL) {
                    cur->next->prev = cur->prev;
                }
                cur->prev->next = cur->next;
                delete cur;
                break;
            }
        }
    }

    void print() {
        Node<T>* cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
            cout << cur->data << ' ';
        }
    }

};
int main () {

}