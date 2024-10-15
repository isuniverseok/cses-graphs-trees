#include <bits/stdc++.h>
using namespace std;
 
bool isPossibleToFormTeams(int n, vector<vector<int>>& friendships, vector<int>& teamAssignments) {
    vector<vector<int>> adj(n + 1);
    for (const auto& friendship : friendships) {
        int u = friendship[0];
        int v = friendship[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    for (int i = 1; i <= n; ++i) {
        if (teamAssignments[i] == 0) {
            queue<int> q;
            q.push(i);
            teamAssignments[i] = 1;
 
            while (!q.empty()) {
                int v = q.front();
                q.pop();
 
                for (int u : adj[v]) {
                    if (teamAssignments[u] == 0) {
                        teamAssignments[u] = 3 - teamAssignments[v]; // Assign the opposite team
                        q.push(u);
                    } else if (teamAssignments[u] == teamAssignments[v]) {
                        return false; // Two friends are in the same team, not possible
                    }
                }
            }
        }
    }
 
    return true;
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> friendships(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        cin >> friendships[i][0] >> friendships[i][1];
    }
 
    vector<int> teamAssignments(n + 1, 0);
 
    if (isPossibleToFormTeams(n, friendships, teamAssignments)) {
        for (int i = 1; i <= n; ++i) {
            cout << teamAssignments[i] << " ";
        }
    } else {
        cout << "IMPOSSIBLE";
    }
 
    cout << endl;
 
    return 0;
}