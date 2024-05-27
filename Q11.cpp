#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValidAllocation(vector<int>& A, int n, int m, int mid) {
    int students = 1;
    int pages = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] > mid)
            return false;
        if (pages + A[i] > mid) {
            students++;
            pages = A[i];
            if (students > m)
                return false;
        }
        else {
            pages += A[i];
        }
    }
    return true;
}

int findMinimumPages(vector<int>& A, int n, int m) {
    if (n < m)
        return -1;

    int low = *max_element(A.begin(), A.end());
    int high = accumulate(A.begin(), A.end(), 0);

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (isValidAllocation(A, n, m, mid)) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    int N = 4;
    vector<int> A = { 12, 34, 67, 90 };
    int M = 2;
    int result = findMinimumPages(A, N, M);
    cout << "Minimum pages: " << result << endl;
    return 0;
}
