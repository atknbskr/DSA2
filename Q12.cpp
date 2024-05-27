#include <iostream>
using namespace std;

int numberSequenceUtil(int m, int n, int currentMax) {
    if (n == 0) {
        return 1;
    }

    int count = 0;
    for (int i = currentMax; i <= m; i++) {
        count += numberSequenceUtil(m, n - 1, 2 * i);
    }

    return count;
}

int numberSequence(int m, int n) {
    return numberSequenceUtil(m, n, 1);
}

int main() {
    int m = 10, n = 4;
    cout << numberSequence(m, n) << endl;

    return 0;
}
