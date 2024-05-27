#include <iostream>
#include <vector>
#include <algorithm>

struct Meeting {
    int start;
    int end;
};


bool compareMeetings(Meeting a, Meeting b) {
    return a.end < b.end;
}

int maxMeetings(int start[], int end[], int N) {
    
    std::vector<Meeting> meetings(N);
    for (int i = 0; i < N; ++i) {
        meetings[i] = { start[i], end[i] };
    }

   
    std::sort(meetings.begin(), meetings.end(), compareMeetings);

    
    int count = 1;
    int lastEnd = meetings[0].end; 

   
    for (int i = 1; i < N; ++i) {
        if (meetings[i].start > lastEnd) { 
            ++count;
            lastEnd = meetings[i].end; 
        }
    }

    return count;
}

int main() {
    int N = 6;
    int start[] = { 1, 3, 0, 5, 8, 5 };
    int end[] = { 2, 4, 6, 7, 9, 9 };

    int result = maxMeetings(start, end, N);
    std::cout << "Maximum number of meetings: " << result << std::endl;

    return 0;
}
