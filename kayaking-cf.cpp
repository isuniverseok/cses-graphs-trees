#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin >> n;
    vector<int> w (2*n);
    for(int i = 0 ; i < (2*n) ; i++){
        cin >> w[i];
    }
    sort(w.begin(),w.end());
    int ans = 0;
    for(int j = (2*n-3) ; j >=1 ; j--){
        ans += (w[j] - w[j-1]);
    }

    cout << ans << endl;
    return 0;
}