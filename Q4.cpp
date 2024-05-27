#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLongestChain(vector<pair<int, int>>& pairs) {
    sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
        });

    int n = pairs.size();
    int count = 1;
    int lastEnd = pairs[0].second;

    for (int i = 1; i < n; ++i) {
        if (pairs[i].first > lastEnd) {
            ++count;
            lastEnd = pairs[i].second;
        }
    }

    return count;
}

int main() {
    int N = 5;
    vector<pair<int, int>> P = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };

    cout << findLongestChain(P) << endl;

    return 0;
}
