#include <iostream>

int main() {
    // Standard namespace for convenience
    using namespace std;

    // --- Part 1: 2D Array Traversal ---
    cout << "--- 2D Array Traversal Example ---" << endl;

    // Declaration and Initialization of a 3x3 array
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Traversing and printing the 2D array row by row
    cout << "Displaying the 2D Array:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl; // Newline after each row
    }

    cout << "\n-------------------------------------\n" << endl;

    // --- Part 2: Matrix Multiplication ---
    cout << "--- Matrix Multiplication Example ---" << endl;

    // Defining the matrices
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int C[2][2] = {{0, 0}, {0, 0}}; // Initialize the result matrix with zeros

    // Performing matrix multiplication: C = A * B
    // The logic: C[i][j] is the dot product of the i-th row of A and the j-th column of B.
    for (int i = 0; i < 2; i++) {       // Iterate through rows of A
        for (int j = 0; j < 2; j++) {   // Iterate through columns of B
            for (int k = 0; k < 3; k++) { // Iterate through columns of A / rows of B
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Printing the resulting matrix C
    cout << "Result of Matrix Multiplication:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0; // Indicates successful execution
}