#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

// problem 11
class Solution {
public:
    
    bool isPossible(int arr[], int n, int m, int mid) {
        int pageCount = 0;  
        int studentCount = 1; 
        for (int i = 0; i < n; i++) {
            if (pageCount + arr[i] <= mid) { 
                pageCount += arr[i];
            } else {
                studentCount++;
                if (studentCount > m || arr[i] > mid) {
                    return false;
                }
                pageCount = arr[i];
            }
        }
        return true;
    }

   
    int findPages(int A[], int N, int M) {
        if (N < M) { 
            return -1;
        }
        int s = 0;  
        int e = accumulate(A, A + N, 0); 
        int ans = -1;
        int mid = s + (e - s) / 2;  
        while (s <= e) { 
            if (isPossible(A, N, M, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
