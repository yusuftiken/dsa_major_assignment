#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// problem 2
struct Job {
    int id;
    int deadline;
    int profit;
};


bool compare(Job a, Job b) {
    return a.profit > b.profit;
}


vector<int> JobScheduling(Job arr[], int n) {
    
    sort(arr, arr + n, compare);

    vector<bool> slot(n, false); 
    vector<int> result(2, 0); 

    
    for (int i = 0; i < n; i++) {
        
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                
                slot[j] = true;
                result[0]++; 
                result[1] += arr[i].profit; 
                break;
            }
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job arr[n];
    cout << "Enter the details of jobs (Job id, Deadline, Profit):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
    }

    
    vector<int> result = JobScheduling(arr, n);
    cout << "Number of jobs done: " << result[0] << endl;
    cout << "Maximum profit: " << result[1] << endl;

    return 0;
}
