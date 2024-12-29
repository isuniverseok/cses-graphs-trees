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
// . (floor) or # (wall) , task is to count number of rooms in n x m grid
using namespace std;
const int max_num = 2500;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
bool vis[max_num][max_num];
int n;
int m ;
string grid[max_num];
void bfs(int r , int c){
   stack< pair<int,int> > st;
   st.push( make_pair(r,c) );
   while(!st.empty()){
    int x = st.top().first;
    int y = st.top().second;
    st.pop();
 
    if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#' || vis[x][y]){
         continue;
    }
    vis[x][y] = true;
    for(int i = 0; i < 4 ; i++){
        st.push( make_pair( x+dx[i] , y+dy[i] ) );
    }
   }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n>> m;
    for(int i =0 ; i < n ; i++){
        cin >> grid[i];
    }
    int ans = 0;
    for(int i =0 ; i < n ; i++){
        for(int j =0 ; j < m ; j++){
            if(grid[i][j] == '.' && !vis[i][j]){
                bfs(i,j);
                ans++;
            }
        }
    }
 
    cout << ans << endl;
    

    return 0;
}