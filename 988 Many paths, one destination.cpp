#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define inf (ll)1e15
#define ll long long
#define lll __int128_t
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define mod 1000000007
// #define mod 998244353
#define pie acos(-1.0)
#define LSOne(i) ((i) & -(i))
#define EPS 1e-9

void dfs(int s, vector<vi> &adj, vi &state, vi &ans){
    state[s] = 1;
    for(int v : adj[s]){
        if(state[v]) continue;
        dfs(v, adj, state, ans);
    }
    ans.push_back(s);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t = 0;
    while(cin >> n){
        vector<vi> adj(n);
        vi deaths;
        for(int i = 0; i < n; i++){
            int cnt; cin >> cnt;
            adj[i].resize(cnt);
            if(!cnt) deaths.push_back(i);
            for(int j = 0; j < cnt; j++) cin >> adj[i][j];
        }

        vi state(n), top;
        dfs(0, adj, state, top);
        reverse(top.begin(), top.end());
    
        vi ways(n); ways[0] = 1; 
        for(int u : top){
            for(int v : adj[u]){
                ways[v] += ways[u];
            }
        }
        
        if(t) cout << "\n";
        int ans = 0;
        for(int i : deaths) ans += ways[i];
        cout << ans << "\n";
        t++;
    } 
}
