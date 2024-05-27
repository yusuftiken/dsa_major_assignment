#include <iostream>
#include <vector>

using namespace std;

// problem 12
class Solution {
public:
    int numberSequence(int m, int n) {
        vector<vector<long long> > dp(m + 1, vector<long long>(n + 1, 0));


        
        for (int i = 1; i <= m; i++) {
            dp[i][1] = 1;
        }

        
        for (int j = 2; j <= n; j++) {
            for (int i = 1; i <= m; i++) {
                for (int k = 1; k <= i / 2; k++) {
                    dp[i][j] += dp[k][j - 1];
                }
            }
        }

        
        long long total = 0;
        for (int i = 1; i <= m; i++) {
            total += dp[i][n];
        }

        return total;
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    Solution sol;
    cout << sol.numberSequence(m, n) << endl;

    return 0;
}
