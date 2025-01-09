#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

vector<unordered_set<int>> vtr;
vector<int> color;
int is_bipartite, zero, one;

void solve(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vtr.assign(n, unordered_set<int>());
        color.assign(n, -1);
        for(int i = 0; i < n; i++){
            int m; cin >> m;
            for(int j = 0; j < m; j++){
                int g; cin >> g; g--;
                if(g < n){
                    vtr[i].insert(g);
                    vtr[g].insert(i);
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                queue<int> q; q.push(i);
                is_bipartite = true;
                color[i] = zero = one = 0;
                while(!q.empty()){
                    int cur = q.front(); q.pop();
                    color[cur] == 0 ? zero++ : one++;
                    for(int i : vtr[cur]){
                        if(color[i] == -1){
                            color[i] = 1-color[cur];
                            q.push(i);
                        }else if(color[i] == color[cur])
                            is_bipartite = false;
                    }
                }
                if(is_bipartite)
                    cnt += max(zero, one);
            }
        }
        cout << cnt << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
