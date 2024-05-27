#include <iostream>
#include <vector>
#include <cstring> 
using namespace std;

// problem 7
class Solution {
public:
    bool isSafe(int id, vector<vector<bool> >& mat, vector<int>& colors, int m, int n) {
        for (int j = 0; j < n; j++) {
            if (j != id && mat[j][id] && colors[j] == colors[id]) 
                return false;
        }  
        return true;
    }
    
    bool solve(int id, vector<vector<bool> >& mat, vector<int>& colors, int m, int n) {
        if (id == n) 
            return true;
    
        for (int i = 1; i <= m; i++) {
            if (isSafe(id, mat, colors, m, n)) {
                colors[id] = i;
                if (solve(id + 1, mat, colors, m, n)) 
                    return true;
                colors[id] = 0;
            }
        }
        return false;
    }

    bool graphColoring(vector<vector<bool> >& mat, int m, int n) {
        vector<int> colors(n, 0);
    
        if (solve(0, mat, colors, m ,n))
            return true;
        return false;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        vector<vector<bool> > graph(n, vector<bool>(n, false));
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = true;
            graph[b - 1][a - 1] = true;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}
