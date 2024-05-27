#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// problem 1
struct Meeting {
    int start;
    int end;
    int index; 
};


bool compare(Meeting a, Meeting b) {
    return a.end < b.end;
}


int maxMeetings(int start[], int end[], int n) {
    
    vector<Meeting> meetings(n);
    for (int i = 0; i < n; i++) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
        meetings[i].index = i;
    }

    
    sort(meetings.begin(), meetings.end(), compare);

    int cnt = 1; 
    int lastEnd = meetings[0].end; 

   
    for (int i = 1; i < n; i++) {
        
        if (meetings[i].start > lastEnd) {
            cnt++;
            lastEnd = meetings[i].end;
        }
    }

    return cnt;
}

int main() {
    int n;
    cout << "Enter the number of meetings: ";
    cin >> n;

    int start[n], end[n];
    cout << "Enter the start times of meetings: ";
    for (int i = 0; i < n; i++)
        cin >> start[i];

    cout << "Enter the end times of meetings: ";
    for (int i = 0; i < n; i++)
        cin >> end[i];

    
    int max_meetings = maxMeetings(start, end, n);
    cout << "Maximum number of meetings that can be accommodated: " << max_meetings << endl;

    return 0;
}
