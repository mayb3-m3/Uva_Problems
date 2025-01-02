#include <bits/stdc++.h>
#define imax INT_MAX
#define llmax INT64_MAX
#define ll long long
#define ull unsigned long long
#define _rand(x,y) min(x,y)+rand()%(abs(y-x)+1)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pss pair<string, string>
#define psi pair<string, int>
#define pis pair<int, string>
#define pie 3.141592653589793238
#define _e 2.718281828459045235

using namespace std;

vector<int> visited;
vector<vector<int>> vtr;
int cnt = 0;
void dfs(int node){
    cnt++;
    visited[node] = 1;
    for(int i : vtr[node]){
        if(visited[i] == -1)
            dfs(i);
    }
}
void solve(){
    while(1){
        int n, m; cin >> n >> m;
        if(n == 0 && m == 0)
            break;
        visited.assign(n+1, -1);
        vtr.assign(n+1, vector<int>());
        vector<vector<int>> pre;
        int mx = -imax;
        for(int i = 0; i < m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            pre.push_back({a, b, c});
            mx = max(mx, c);
        }
        for(auto v : pre){
            if(v[2] == mx){
                vtr[v[0]].push_back(v[1]);
                vtr[v[1]].push_back(v[0]);
            }
        }
        mx = 2;
        for(int i = 1; i <= n; i++){
            cnt = 0;
            if(visited[i] == -1){
                dfs(i);
                mx = max(mx, cnt);
            }
        }
        cout << mx << endl;
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
