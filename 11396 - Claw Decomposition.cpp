#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

void solve(){
    while(true){
        int n; cin >> n;
        if(n == 0)
            break;
        vector<vector<int>> nei(n, vector<int>());
        vector<int> color(n, -1);
        while(true){
            int a, b; cin >> a >> b;
            if(a == 0 && b == 0)
                break;
            a--, b--;
            nei[a].push_back(b);
            nei[b].push_back(a);
        }
        queue<int> q;
        q.push(0), color[0] = 0;
        bool bipartite = true;
        while(!q.empty() && bipartite){
            int u = q.front(); q.pop();
            for(int i : nei[u]){
                if(color[i] == -1){
                    color[i] = 1-color[u];
                    q.push(i);
                }else if(color[i] == color[u]){
                    bipartite = false;
                    break;
                }
                
            }
        }
        if(bipartite) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
