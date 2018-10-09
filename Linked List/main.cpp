#include <iostream>

using namespace std;

class Node {
public:
    Node* next;
    Node* prev;
    int data;
    Node (int _data) {
        data = _data;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList() {
        size = 0;
        head = tail = nullptr;
    }

    void insertFirst(int x) {
        Node* cur = new Node(x);
        size++;
        if (head == nullptr) {
            head = cur;
            tail = cur;
        }else {
            head->prev = cur;
            cur->next = head;
            head = cur;
        }
    }

    void insertLast(int x) {
        Node* cur = new Node(x);
        size++;
        if (tail == nullptr) {
            head = cur;
            tail = cur;
        }else {
            tail->next = cur;
            cur->prev = tail;
            tail = cur;
        }
    }

    int cnt(int x) {
        Node* cur = head;
        int cnt = 0;
        while (cur != nullptr) {
            cnt += (cur->data == x);
            cur = cur->next;
        }
        return cnt;
    }

    int getNth(int x) {
        Node* cur = head;
        while(cur != nullptr) {
            if (x-- == 0) return cur->data;
            cur = cur->next;
        }
        return -1;
    }



    void deleteFirst() {
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        else tail = nullptr;
    }

    void deleteLast() {
        tail = tail->prev;
        if (tail != nullptr) tail->next = nullptr;
        else head = nullptr;
    }

    void del(int x) {
        Node* cur = head;
        while (cur != nullptr && cur->data != x) cur = cur->next;
        if (cur == nullptr) return;
        if (cur == head) deleteFirst();
        else if (cur == tail) deleteLast();
        else {
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
        }
    }

    void print() {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur != head) cout << " ";
            cout << (cur->data);
            cur = cur->next;
        }
        cout << endl;
    }

};

int main () {
    int n, x;
    string s;
    LinkedList ls = LinkedList();
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> s;
        if (s == "insertFirst") {
            cin >> x;
            ls.insertFirst(x);
        }
        if (s == "delete") {
            cin >> x;
            ls.del(x);
        }
        if (s == "deleteFirst") {
            ls.deleteFirst();
        }
        if (s == "deleteLast") {
            ls.deleteLast();
        }
        if (s == "insertLast") {
            cin >> x;
            ls.insertLast(x);
        }
        if (s == "cnt") {
            cin >> x;
            cout << ls.cnt(x) << endl;
        }
        if (s == "getNth") {
            cin >> x;
            cout << ls.getNth(x) << endl;
        }
    }
    ls.print();
}