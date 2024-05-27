#include <iostream>
#include <algorithm>
using namespace std;

int findKthElement(int arr1[], int n, int arr2[], int m, int k) {
    // Ensure arr1 is the smaller array to minimize binary search time
    if (n > m) {
        return findKthElement(arr2, m, arr1, n, k);
    }

    int low = max(0, k - m), high = min(k, n);

    while (low <= high) {
        int partition1 = (low + high) / 2;
        int partition2 = k - partition1;

        int maxLeft1 = (partition1 == 0) ? INT_MIN : arr1[partition1 - 1];
        int minRight1 = (partition1 == n) ? INT_MAX : arr1[partition1];

        int maxLeft2 = (partition2 == 0) ? INT_MIN : arr2[partition2 - 1];
        int minRight2 = (partition2 == m) ? INT_MAX : arr2[partition2];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            return max(maxLeft1, maxLeft2);
        }
        else if (maxLeft1 > minRight2) {
            high = partition1 - 1;
        }
        else {
            low = partition1 + 1;
        }
    }

    return -1;
}

int main() {
    int arr1[] = { 2, 3, 6, 7, 9 };
    int arr2[] = { 1, 4, 8, 10 };
    int k = 5;
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    int result = findKthElement(arr1, n, arr2, m, k);
    cout << result << endl;

    return 0;
}
