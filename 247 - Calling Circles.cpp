#include <bits/stdc++.h>
#define pii pair<int, int>
#define pss pair<string, string>

using namespace std;

vector<vector<int>> vtr1, vtr2;
vector<int> states, vtr, circle;

void dfs(int node, int pass){
    if(pass == 2)
        circle.push_back(node);
    states[node] = 1;
    vector<int> nei = (pass == 1) ? vtr1[node] : vtr2[node];
    for(int i : nei){
        if(states[i] == -1)
            dfs(i, pass);
    }
    vtr.push_back(node);
}

void print(unordered_map<int, string> to_name){
    int l = circle.size();
    cout << to_name[circle[0]];
    for(int i = 1; i < l; i++)
        cout << ", " << to_name[circle[i]];
    cout << endl;
    circle.clear();
}

void solve(){
    int t = 1, first = true;
    while(true){
        int n, m; cin >> n >> m;
        if(n == 0 && m == 0)
            break;

        unordered_set<string> st;
        vector<pss> pr;
        for(int i = 0; i < m; i++){
            string str1, str2;
            cin >> str1 >> str2;
            st.insert({str1, str2});
            pr.push_back({str1, str2});
        }

        unordered_map<string, int> to_num;
        unordered_map<int, string> to_name;
        int pos = 0;
        for(string str : st){
            to_num[str] = pos;
            to_name[pos] = str;
            pos++;
        }

        vtr1.assign(n, vector<int>());
        vtr2.assign(n, vector<int>());
        for(auto p : pr){
            int from = to_num[p.first];
            int to = to_num[p.second];
            vtr1[from].push_back(to);
            vtr2[to].push_back(from);
        }

        states.assign(n, -1);
        vtr.clear();
        for(int i = 0; i < n; i++)
            if(states[i] == -1)
                dfs(i, 1);
        
        if(!first)
            cout << endl;
        first = false;
        cout << "Calling circles for data set " << t++ << ":\n";

        states.assign(n, -1);
        for(int i = n-1; i >= 0; i--){
            if(states[vtr[i]] == -1){
                dfs(vtr[i], 2);
                print(to_name);
            }
        }    
    }    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
