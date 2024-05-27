#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// problem 6
void backtrack(int x, int y, int N, vector<vector<int> >& m, string path, vector<string>& paths) {
    
    if (x == N - 1 && y == N - 1) {
        paths.push_back(path);
        return;
    }

    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char directions[] = {'U', 'D', 'L', 'R'};

    
    for (int i = 0; i < 4; ++i) {
        int newx = x + dx[i];
        int newy = y + dy[i];

        
        if (newx >= 0 && newx < N && newy >= 0 && newy < N && m[newx][newy] == 1) {
            
            m[x][y] = 0;
            
            backtrack(newx, newy, N, m, path + directions[i], paths);
            
            m[x][y] = 1;
        }
    }
}

vector<string> printPath(int N, vector<vector<int> >& m) {
    vector<string> paths;
    
    if (m[0][0] == 0)
        return paths;

    backtrack(0, 0, N, m, "", paths);
    
    sort(paths.begin(), paths.end());
    return paths;
}

int main() {
    int N = 4;
    vector<vector<int> > m(N, vector<int>(N, 0));
    m[0][0] = 1;
    m[1][0] = 1;
    m[1][1] = 1;
    m[1][3] = 1;
    m[2][0] = 1;
    m[2][1] = 1;
    m[3][1] = 1;
    m[3][2] = 1;
    m[3][3] = 1;

    vector<string> paths = printPath(N, m);
    if (paths.empty()) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < paths.size(); i++) {
            cout << paths[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
