#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

void solve(){
    int t; cin >> t;
    while(t--){
        int v, e; cin >> v >> e;
        vector<vector<int>> nei(v, vector<int>());
        vector<int> color(v, -1);
        for(int i = 0; i < e; i++){
            int a, b; cin >> a >> b;
            nei[a].push_back(b);
            nei[b].push_back(a);
        }
        int cnt = 0;
        for(int i = 0; i < v; i++){
            bool bipartite = true;
            if(color[i] == -1){
                int zero = 0, one = 0;
                queue<int> q;
                q.push(i); color[i] = 0;
                while(!q.empty() && bipartite){
                    int u = q.front(); q.pop();
                    color[u] == 0 ? zero++ : one++;
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
                if(bipartite)
                    cnt += max(1, min(zero, one));
            }
        }
        if(cnt) cout << cnt <<endl;
        else cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
