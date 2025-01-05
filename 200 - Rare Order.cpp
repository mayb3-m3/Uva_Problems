#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<string> vtr;
    int mx = -1;
    while(1){
        string str; cin >> str;
        if(str == "#")
            break;
        str = "A" + str;
        vtr.push_back(str);
        mx = max(mx, int(str.size()));
    }
    for(string& str : vtr)
        str = str + string(mx-str.size(), '#');
    int l = vtr.size();
    string ans;
    unordered_set<char> st{};
    for(int i = 1; i < mx; i++){
        for(int j = 0; j < l-1; j++){
            int c1 = vtr[j][i-1], c2 = vtr[j][i];
            int c3 = vtr[j+1][i-1], c4 = vtr[j+1][i];
            if(c1 == c3 && c1 != '#' && c2 != '#' && c4 != '#'){
                if(st.find(c2) == st.end())
                    ans += c2, st.insert(c2);
                if(st.find(c4) == st.end())
                    ans += c4, st.insert(c4);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
