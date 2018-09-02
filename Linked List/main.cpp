#include <iostream>

using namespace std;

class Node {

public:
    Node* next = (NULL);
    Node* prev = (NULL);
    int data;

    Node (int _data = 0) {
        data = _data;
        next = (NULL);
        prev = (NULL);
    }
};

class LinkedList {

public:
    Node* head;
    Node* tail;
    int Size;

    LinkedList () {
        head = new Node(NULL);
        tail = head;
        Size = 0;
    }

    void add(int val) {
        Node* temp = new Node(val);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        Size++;
    }

    bool empty() {
        return (Size == 0);
    }

    void remove_ith(int id) {
        if (id > Size) {
            return;
        }
        Node* cur = head;
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
        Node* cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
            cout << cur->data << ' ';
        }
    }

};
int main () {

}