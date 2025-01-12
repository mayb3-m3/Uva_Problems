#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

vector<vector<int>> vtr1, vtr2;
vector<int> states;
vector<int> vtr;

void scc(int node, int pass){
    states[node] = 1;
    vector<int> nei = pass == 1 ? vtr1[node] : vtr2[node];
    for(int i : nei)
        if(states[i] == -1)
            scc(i, pass);
    vtr.push_back(node);
}

void solve(){
    while(true){
        int n, m; cin >> n >> m;
        if(n == 0 && m == 0)
            break;
        vtr1.assign(n, vector<int>());
        vtr2.assign(n, vector<int>());
        states.assign(n, -1);
        vtr.clear();
        for(int i = 0; i < m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            vtr1[a].push_back(b);
            if(c == 2)
                vtr1[b].push_back(a);
        }
        for(int i = 0; i < n; i++)
            for(int j : vtr1[i])
                vtr2[j].push_back(i);
        for(int i = 0; i < n; i++)
            if(states[i] == -1)
                scc(i, 1);
        states.assign(n, -1);
        int cnt = 0;
        for(int i = n-1; i >= 0; i--)
            if(states[vtr[i]] == -1)
                ++cnt, scc(vtr[i], 2);
        if(cnt != 1)
            cnt = 0;
        cout << cnt << endl;
    }    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
