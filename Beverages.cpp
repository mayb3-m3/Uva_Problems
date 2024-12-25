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
#define pie 3.141592653589793238
#define _e 2.718281828459045235

using namespace std;

void solve(){
    int n, m, cas = 1;
    while(cin >> n){
        unordered_map<string, int> mp1;
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            mp1[s];
        }
        cin >> m;
        unordered_map<string, vector<string>> mp2;
        for(int i = 0; i < m; i++){
            string s1, s2; cin >> s1 >> s2;
            mp1[s2]++;
            mp2[s1].push_back(s2);
        }
        priority_queue<pis, vector<pis>, greater<pis>> pq;
        for(auto i : mp1)
            if(i.second == 0)
                pq.push({i.second, i.first});
        vector<string> ans;
        while(!pq.empty()){
            string str = pq.top().second; pq.pop();
            ans.push_back(str);
            for(string s : mp2[str]){
                mp1[s]--;
                if(mp1[s] > 0)
                    continue;
                pq.push({mp1[s], s});
            }
        }
        cout << "Case #" << cas++ <<": Dilbert should drink beverages in this order: ";
        for(int i = 0; i < int(ans.size()); i++){
            if(i == 0)
                cout << ans[i];
            else
                cout << " " << ans[i];
        }
        cout << ".\n\n";
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
