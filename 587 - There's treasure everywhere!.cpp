#include <bits/stdc++.h>
#define pii pair<int, int>
#define pss pair<string, string>

using namespace std;

vector<vector<int>> aj1, aj2;
vector<int> states;
vector<int> vtr;

void dfs(int node, int pass){
    states[node] = 1;
    vector<int> nei = (pass == 1) ? aj1[node] : aj2[node];
    for(int i : nei)
        if(states[i] == -1)
            dfs(i, pass);
    vtr.push_back(node);
}
void solve(){
    while(true){
        int n, m; cin >> n >> m;
        cin.ignore();
        if(n == 0 && m == 0)
            break;
        unordered_map<string, int> to_num;
        for(int i = 0; i < n; i++){
            string str;
            getline(cin, str);
            to_num[str] = i;
        }

        aj1.assign(n, vector<int>());
        aj2.assign(n, vector<int>());
        for(int i = 0; i < m; i++){
            string str1, str2;
            getline(cin, str1);
            getline(cin, str2);
            int a = to_num[str1], b = to_num[str2];
            aj1[a].push_back(b);
            aj2[b].push_back(a);
        }
        vtr.clear();
        states.assign(n, -1);
        for(int i = 0; i < n; i++)
            if(states[i] == -1)
                dfs(i, 1);

        states.assign(n, -1);
        int cnt = 0;
        for(int i = n-1; i >= 0; i--)
            if(states[vtr[i]] == -1)
                cnt++, dfs(vtr[i], 2);
        cout << cnt << endl;
    }   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
