#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<long long int> a(n);
    unordered_map<int, long long int> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int complement = x - a[i];
        if (m.find(complement) != m.end()) {
            cout << m[complement] + 1 << " " << i + 1 << endl;
            return 0;
        }
        m[a[i]] = i; 
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
