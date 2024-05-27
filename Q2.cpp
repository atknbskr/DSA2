#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

pair<int, int> jobScheduling(Job arr[], int n) {
    sort(arr, arr + n, comparison);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (arr[i].deadline > maxDeadline)
            maxDeadline = arr[i].deadline;

    vector<int> slot(maxDeadline + 1, -1);

    int countJobs = 0, maxProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = arr[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                countJobs++;
                maxProfit += arr[i].profit;
                break;
            }
        }
    }

    return { countJobs, maxProfit };
}

int main() {
    int N = 4;
    Job jobs[] = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    pair<int, int> result = jobScheduling(jobs, N);
    cout << result.first << " " << result.second << endl;
    return 0;
}
