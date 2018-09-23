#include <iostream>

using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int data;
    int subtree_size;
    int level;
    int height;
    int cnt;
    Node (int _data = 0, int _level = 0) {
        data = _data;
        level = _level;
        left = nullptr;
        right = nullptr;
        subtree_size = 1;
        height = 1;
        cnt = 1;
    }
    void updateSubtreeSize() {
        int size = 1;
        if (this->left != nullptr) size += this->left->subtree_size;
        if (this->right != nullptr) size += this->right->subtree_size;
        this->subtree_size = size;
    }
    void updateHeight() {
        if (this->left != nullptr) height = max(height, this->left->height + 1);
        if (this->right != nullptr) height = max(height, this->right->height + 1);
    }
    void increaseCounter() {
        cnt++;
    }
    void print() {
        cout << data << ' ' << level << ' ' << subtree_size;
    }
};

class BST {
public:
    Node* root;
    int height;
    int _size;

    BST () {
        root = nullptr;
        height = 0;
        _size = 0;
    }

    Node* insert(int value, Node* t, int level = 1) {
        if (t == nullptr) {
            t = new Node(value, level);
            _size++;
            height = max(height, level);
        }else {
            if (t->data == value) {
                t->increaseCounter();
            }
            if (t->data < value) {
                t->right = insert(value, t->right, level + 1);
            }else if (t->data != value){
                t->left = insert(value, t->left, level + 1);
            }
        }
        t->updateSubtreeSize();
        t->updateHeight();
        return t;
    }

    void insert(int value) {
        root = insert(value, root);
    }

    int getHeight() {
        return height;
    }

    int getSize() {
        return _size;
    }

    int getKth(int k, Node* t) {
        int size_left = t->left == nullptr ? 0 : t->left->subtree_size;
        if (k - 1 == size_left) {
            return t->data;
        }
        return k <= size_left ? getKth(k, t->left) : getKth(k - size_left - 1, t->right);
    }

    int getKth(int k) {
        return getKth(k, root);
    }

    void inOrderTraversal(Node* t) {
        if (t->left != nullptr) inOrderTraversal(t->left);
        cout << t->data << ' ' << t->cnt << endl;
        if (t->right != nullptr) inOrderTraversal(t->right);
    }

    void preOrderTraversal(Node* t) {
        cout << t->data << endl;
        if (t->left != nullptr) preOrderTraversal(t->left);
        if (t->right != nullptr) preOrderTraversal(t->right);
    }

    void postOrderTraversal(Node* t) {
        if (t->left != nullptr) postOrderTraversal(t->left);
        if (t->right != nullptr) postOrderTraversal(t->right);
        cout << t->data << endl;
    }

    void printLeafs(Node* t) {
        if (t->left == nullptr && t->right == nullptr) cout << t->data << endl;
        if (t->left != nullptr) printLeafs(t->left);
        if (t->right != nullptr) printLeafs(t->right);
    }

    void print(Node* t) {
        if (t->left != nullptr) print(t->left);
        if ((t->left != nullptr) ^ (t->right != nullptr)) cout << t->data << endl;
        if (t->right != nullptr) print(t->right);
    }

    bool isBalanced(Node* t) {
        if (t == nullptr) return true;
        int height_left = t->left == nullptr ? 0 : t->left->height;
        int height_right = t->right == nullptr ? 0 : t->right->height;
        if (abs(height_left - height_right) > 1) return false;
        return isBalanced(t->left) & isBalanced(t->right);
    }

    void print(int mode) {
        if (mode == 1) {
            inOrderTraversal(root);
        }
        if (mode == 2) {
            preOrderTraversal(root);
        }
        if (mode == 3) {
            postOrderTraversal(root);
        }
        if (mode == 4) {
            printLeafs(root);
        }
        if (mode == 5) {
            print(root);
        }
    }

    void isBalanced() {
        if (isBalanced(root)) {
            cout << "YES";
        }else {
            cout << "NO";
        }
    }
};

int main () {
    BST mybst = BST();
    int x;
    while (cin >> x) {
        if (x == 0) break;
        mybst.insert(x);
    }
    mybst.print(1);
}