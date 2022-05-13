#include <iostream>
using namespace std;

int bubbleSort(int A[], int N) {

    int sw = 0;
    bool flag = 1;
    for (int i = 0; flag; i++) {
        flag = 0;
        for (int j = N - 1; j >= i + 1; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                flag = 1;
                sw++;
            }
        }
    }
    return sw;
}

int main() {
    int A[100], N, sw;
    // A = [100, 101, 102, 103, 104, 105, 106, 107, 303, 20, 1234, 31, 444, 24];
    for (int i = 0; i < N; i++) cin >> A[i];

    sw = bubbleSort(A, N);

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;

    return 0;
}

