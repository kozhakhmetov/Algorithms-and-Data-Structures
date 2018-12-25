#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


template <typename T>
struct Fenwick {
    vector <T> tree;
    int size;

    Fenwick(int _size) {
        size = _size;
        tree = vector<T>(size + 1);
    }

    void add(int i, T val) {
        for(;i < size; i += (i & -i)) {
            tree[i] += val;
        }
    }
    T get(int i) {
        T res = 0;
        for(;i > 0; i -= (i & -i)) {
            res += tree[i];
        }
        return res;
    }
};

int main () {
    return 0;
}