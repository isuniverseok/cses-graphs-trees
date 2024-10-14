#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void find_route(int n, int m, const vector<pair<int, int>>& connections) {
    vector<vector<int>> adj(n + 1);  
    vector<int> dist(n + 1, -1);     
    vector<int> parent(n + 1, -1);   

    for (const auto& connection : connections) {
        int a = connection.first, b = connection.second;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    queue<int> q;
    q.push(1);      
    dist[1] = 0;    
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {  
                dist[neighbor] = dist[node] + 1;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    // Check if we reached node n
    if (dist[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path;
        for (int cur = n; cur != -1; cur = parent[cur]) {
            path.push_back(cur);
        }
        reverse(path.begin(), path.end()); 
       
        cout << path.size() << endl;       
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> connections(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        connections[i] = {a, b};
    }

    find_route(n, m, connections);

    return 0;
}
