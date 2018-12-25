#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

template <typename T>
void QuickSort(T* l, T* r) {
    if (l < r) {
        T pivot = *(l + rand() % (r - l + 1));
        T* i = l;
        T* j = r;
        while (i <= j) {
            while (*i < pivot) i++;
            while (*j > pivot) j--;
            if (i <= j) {
                swap(*i, *j);
                i++;
                j--;
            }
        }
        QuickSort(l, j);
        QuickSort(i, r);
    }
}
