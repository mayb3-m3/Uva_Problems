#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<string> vtr;
    int mx = -1;
    while(1){
        string str; cin >> str;
        if(str == "#")
            break;
        vtr.push_back(str);
        mx = max(mx, int(str.size()));
    }
    for(string& str : vtr)
        str = str + string(mx-str.size(), '#');
    int l = vtr.size();
    string ans;
    unordered_set<char> st;
    for(int i = 0; i < mx; i++){
        for(int j = 0; j < l-1; j++){
            char ch1 = vtr[j][i];
            char ch2 = vtr[j+1][i];
            if(ch1 != ch2 && ch1 != '#' && ch2 != '#'){
                if(st.find(ch1) == st.end())
                    ans += ch1, st.insert(ch1);
                if(st.find(ch2) == st.end())
                    ans += ch2, st.insert(ch2);
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
