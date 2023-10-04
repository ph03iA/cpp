#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Perform Gaussian elimination with partial pivoting
bool gaussianElimination(vector<vector<double>>& A, vector<double>& b, vector<double>& x) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        int pivotRow = i;

        for (int j = i + 1; j < n; j++) {
            if (abs(A[j][i]) > abs(A[pivotRow][i])) {
                pivotRow = j;
            }
        }

        if (abs(A[pivotRow][i]) < 1e-10) {
            return false;
        }

        swap(A[i], A[pivotRow]);
        swap(b[i], b[pivotRow]);

        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i] / A[i][i];
            for (int k = i; k < n; k++) {
                A[j][k] -= factor * A[i][k];
            }
            b[j] -= factor * b[i];
        }
    }

    x.resize(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++) {
            sum += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / A[i][i];
    }

    return true;
}

int main() {
    int n = 3; // Size of the system (3x3 in this case)

    vector<vector<double>> A = {{2, 1, -1},
                                {-3, -1, 2},
                                {-2, 1, 2}};
    vector<double> b = {8, -11, -3};
    vector<double> x;

    if (gaussianElimination(A, b, x)) {
        cout << "Solution:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "x[" << i << "] = " << x[i] << endl;
        }
    } else {
        cout << "The matrix is singular. No unique solution exists." << endl;
    }

    return 0;
}
