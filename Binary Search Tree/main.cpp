#include <iostream>

using namespace std;

class Node {
public:
    Node* left = NULL;
    Node* right = NULL;
    int data;
    int level;
    Node (int _data = 0, int _level = 0) {
        data = _data;
        level = _level;
    }
};

class BST {
public:
    Node* root;
    int height = 0;
    int _size = 0;

    BST () {
        root = NULL;
    }

    void add (int val) {
        int flag = 1;
        if (_size == 0) {
            root = new Node(val, 1);
            height = 1;
        }else {
            Node* cur = root;
            while (true) {
                if (cur->data == val) {
                    flag = 0;
                    break;
                }
                if (cur->data > val) {
                    if (cur->right == NULL) {
                        cur->right = new Node(val, cur->level + 1);
                        updateHeight(cur->level + 1);
                        break;
                    }else {
                        cur = cur->right;
                    }
                }else {
                    if (cur->left == NULL) {
                        cur->left = new Node(val, cur->level + 1);
                        updateHeight(cur->level + 1);
                        break;
                    }else {
                        cur = cur->left;
                    }
                }
            }
        }
        _size += flag;
    }

    int getHeight() {
        return height;
    }

    void updateHeight(int level) {
        height = max(height, level);
    }

    int getSize() {
        return _size;
    }
};

int main () {
    BST mybst = BST();
    int x;
    while (cin >> x) {
        if (x == 0) break;
        mybst.add(x);
    }
    cout << mybst.getHeight();
}