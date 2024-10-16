#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];  
int parent[MAXN];       
bool visited[MAXN];     
int start = -1, e = -1;


bool dfs(int node, int par) {
    visited[node] = true;
    parent[node] = par;
    
    for (int neighbor : adj[node]) {
        if (neighbor == par) continue;  
        if (visited[neighbor]) {
            start = neighbor;
            e = node;
            return true;
        }
        parent[neighbor] = node;
        if (dfs(neighbor, node)) return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                break;
            }
        }
    }
    if (start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        
        vector<int> cycle;
        cycle.push_back(start);
        for (int v = e; v != start; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(start);
        
        cout << cycle.size() << endl;
        for (int city : cycle) {
            cout << city << " ";
        }
        cout << endl;
    }

    return 0;
}
