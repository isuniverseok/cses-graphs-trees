#include <cassert>
#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ciso646>
#include <cstdarg>
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <random>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <memory>
#include <string>
#include <tuple>
#include <utility>
#include <exception>
#include <stdexcept>
#include <functional>
#include <type_traits>
using namespace std;

int dx[4] = {-1, 1, 0, 0}; // U, D, L, R
int dy[4] = {0, 0, -1, 1}; // U, D, L, R
char moveDir[4] = {'U', 'D', 'L', 'R'};

int n, m;
vector<string> labyrinth;
vector<vector<bool> > visited;
vector<vector<int> > dist;
vector<vector<pair<int, int> > > parent;

// Function to check if a cell is inside the labyrinth and not visited yet
bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && labyrinth[x][y] != '#' && !visited[x][y];
}

int main() {
    cin >> n >> m;
    labyrinth.resize(n);
    visited.assign(n, vector<bool>(m, false));
    dist.assign(n, vector<int>(m, -1));
    parent.assign(n, vector<pair<int, int> >(m, make_pair(-1,-1)));
    
    pair<int, int> start, end;
    
    // Input the labyrinth and find the start 'A' and end 'B'
    for (int i = 0; i < n; i++) {
        cin >> labyrinth[i];
        for (int j = 0; j < m; j++) {
            if (labyrinth[i][j] == 'A') start = make_pair(i,j);
            if (labyrinth[i][j] == 'B') end = make_pair(i,j);
        }
    }
    
    // BFS initialization
    queue<pair<int, int> > q;
    q.push(start);
    visited[start.first][start.second] = true;
    dist[start.first][start.second] = 0;
    
    bool found = false;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
    
        if (x == end.first && y == end.second) {
            found = true;
            break;
        }
        
        
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if (isValid(newX, newY)) {
                visited[newX][newY] = true;
                dist[newX][newY] = dist[x][y] + 1;
                parent[newX][newY] = make_pair(x,y);
                q.push(make_pair(newX,newY));
            }
        }
    }
    
    if (found) {
        cout << "YES\n";
        cout << dist[end.first][end.second] << "\n";
        
        // Reconstruct the path
        string path;
        pair<int, int> current = end;
        while (current != start) {
            pair<int, int> p = parent[current.first][current.second];
            for (int i = 0; i < 4; i++) {
                if (p.first + dx[i] == current.first && p.second + dy[i] == current.second) {
                    path.push_back(moveDir[i]);
                    break;
                }
            }
            current = p;
        }
        
        reverse(path.begin(), path.end());
        cout << path << "\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}