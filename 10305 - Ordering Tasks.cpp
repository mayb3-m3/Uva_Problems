#include <bits/stdc++.h>
#define pii pair<int, int>
#define pss pair<string, string>
#define pis pair<int, string>
#define psi pair<string, int>

using namespace std;

vector<vector<int>> ajl;
vector<int> vtr, states;

void dfs(int node){
    states[node] = 1;
    for(int i : ajl[node])
        if(states[i] == -1)
            dfs(i);
    vtr.push_back(node);
}
void solve(){
    while(true){
        int n, m; cin >> n >> m;
        if(n+m == 0)
            break;
        ajl.assign(n, vector<int>());
        states.assign(n, -1);
        vtr.clear();
        for(int i = 0; i < m; i++){
            int a, b; cin >> a >> b;
            a--, b--;
            ajl[b].push_back(a);
        }

        for(int i = 0; i < n; i++)
            if(states[i] == -1)
                dfs(i);

        for(int i : vtr)
            cout << i+1 << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
