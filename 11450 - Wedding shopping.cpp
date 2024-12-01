#include <bits/stdc++.h>

#define imax INT_MAX
#define llmax INT64_MAX
#define ll long long
#define ull unsigned long long
#define _rand(x,y) min(x,y)+rand()%(abs(y-x)+1)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pss pair<string, string>
#define psi pair<string, int>
#define pis pair<int, string>
#define mod 1000000007
#define pie 3.141592653589793238
#define _e 2.718281828459045235

using namespace std;

void solve(){
    int t; cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        vector<vector<int>> vtr(n);
        for(int i = 0; i < n; i++){
            int size; cin >> size;
            vector<int> t(size);
            for(int j = 0; j < size; j++)
                cin >> t[j];
            vtr[i] = t;
        }
        vector<int> ans(vtr.back());
        vtr.pop_back();
        for(auto v : vtr){
            unordered_set<int> st;
            for(int i : v){
                for(int j : ans)
                    st.insert(i+j);
            }
            ans.clear();
            for(int i : st)
                if(i <= m)
                    ans.push_back(i);
        }
        if(ans.empty())
            cout << "no solution\n";
        else
            cout << *max_element(ans.begin(), ans.end()) << endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
