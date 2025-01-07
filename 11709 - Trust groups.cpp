#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vtr, rev;
vector<int> state;
stack<int> stc;

void dfs(int node, int pass){
    state[node] = 1;
    vector<int> nei{vtr[node]};
    if(pass == 2) nei = rev[node];
    for(int i : nei)
        if(state[i] == -1)
            dfs(i, pass);
    if(pass == 1) stc.push(node);
}
void solve(){
    while(1){
        int n, m; cin >> n >> m;
        if(n == 0 && m == 0)
            break;
        vtr.assign(n, vector<int>());
        rev.assign(n, vector<int>());
        state.assign(n, -1);
        cin.ignore();
        //mapping all the names
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++){
            string str;
            getline(cin, str);
            mp[str] = i;
        }
        //building the graph
        for(int i = 0; i < m; i++){
            string str1, str2;
            getline(cin, str1);
            getline(cin, str2);
            vtr[mp[str1]].push_back(mp[str2]);
        }
        //transposing the graph
        for(int i = 0; i < int(vtr.size()); i++)
            for(int v : vtr[i])
                rev[v].push_back(i);
        //first pass for the stack value
        for(int i = 0; i < n; i++)
            if(state[i] == -1)
                dfs(i, 1);
        //resetting the state ans initialize the cnt
        state.assign(n, -1);
        int cnt = 0;
        //second pass for cc
        for(int i = 0; i < n; i++){
            if(state[stc.top()] == -1)
                dfs(stc.top(), 2), cnt++;
            stc.pop();
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
