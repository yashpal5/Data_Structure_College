#include <iostream>
using namespace std;

int main(){

    int A[3][3]={{1,2,8},{2,3,8}};
    int B[3][3]={{4,2,8},{2,6,8}};
    int C[3][3]={{4,2,8},{2,6,8}};
    int D[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            D[i][j] = A[i][j] + B[i][j] + C[i][j];
        }
    }

    cout<<"The sum of A and B metrics are :"<<endl;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<D[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}