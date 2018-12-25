#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

class Matrix {
public:
    static int modulo;
    int size_n;
    int size_m;
    vector <vector <int> > matrix;

    Matrix(int n, int m) {
        size_n = n;
        size_m = m;
        matrix = vector <vector <int>>(size_n, vector<int>(size_m, 0));
    }
    Matrix(vector <vector <int>> _matrix) {
        matrix = _matrix;
        size_m = (int)(matrix[0].size());
        size_n = (int)(matrix.size());
        matrix = _matrix;
    }
    Matrix(int n) {
        size_n = n;
        size_m = n;
        matrix = vector <vector <int>>(size_n, vector<int>(size_m, 0));
        for(int i = 0; i < n; ++i) matrix[i][i] = 1;
    }

    Matrix operator*(const Matrix &other) {
        if (other.size_n != size_m) {
            cout << "Cannot multiply due to the size difference\n";
        }
        Matrix result = Matrix(size_n, other.size_m);
        for(int i = 0; i < result.size_n; ++i) {
            for(int j = 0; j < result.size_m; ++j) {
                for(int k = 0; k < size_m; ++k) {
                    result.matrix[i][j] += (matrix[i][k] * other.matrix[k][j]) % modulo;
                    result.matrix[i][j] %= modulo;
                }
            }
        }
        return result;
    }

    Matrix operator^(const int &other) {
        Matrix result = Matrix(size_n);
        Matrix temp = *this;
        int power = other;
        while (power > 0) {
            if (power & 1) {
                result = result * temp;
            }
            temp = temp * temp;
            power /= 2;
        }
        return result;
    }

    void print() {
        for(int i = 0; i < size_n; ++i) {
            for(int j = 0; j < size_m; ++j) {
                cout << matrix[i][j] << ' ';
            }
            cout << "\n";
        }
    }
};
int Matrix::modulo = 1000000007;

int main () {
    return 0;


}