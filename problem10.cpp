#include <iostream>
#include <vector>

using namespace std;

// problem 10
int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
    int n = arr1.size();
    int m = arr2.size();
    int i = 0, j = 0;
    int count = 0;
    int result;

    while (i < n && j < m && count < k) {
        if (arr1[i] <= arr2[j]) {
            result = arr1[i++];
        } else {
            result = arr2[j++];
        }
        count++;
    }

    while (i < n && count < k) {
        result = arr1[i++];
        count++;
    }

    while (j < m && count < k) {
        result = arr2[j++];
        count++;
    }

    return result;
}

int main() {
    int n, m;
    cout << "Enter the size of arr1: ";
    cin >> n;
    vector<int> arr1(n);
    cout << "Enter elements of arr1: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    cout << "Enter the size of arr2: ";
    cin >> m;
    vector<int> arr2(m);
    cout << "Enter elements of arr2: ";
    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    cout << k<< "th Element: " << kthElement(arr1, arr2, k) << endl;

    return 0;
}
