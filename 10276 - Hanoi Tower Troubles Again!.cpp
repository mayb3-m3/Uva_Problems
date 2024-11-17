#include <bits/stdc++.h>

#define imax INT_MAX
#define llmax INT64_MAX
#define ll long long
#define sorted(x) sort(x.begin() , x.end())
#define rsorted(x) sort(x.rbegin() , x.rend())
#define nextp(x) next_permutation(x.begin(), x.end())
#define _rand(x,y) min(x,y)+rand()%(abs(y-x)+1)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pss pair<string, string>
#define psi pair<string, int>
#define pis pair<int, string>
#define mod 1000000007
#define pie 3.141592653589793238
#define e_ 2.718281828459045235

using namespace std;

void solve(){
    unordered_map<ll, ll> mp;
    for(ll i = 1; i <= 1e3; i++)
        mp[i*i] = 1;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<stack<int>> vtr(n);
        int count = 0;
        for(int i = 1; i <= 1e4; i++){
            int any = 0;
            for(auto &s : vtr){
                if(s.empty()){
                    s.push(i), any = 1, count++;
                    break;
                }
                else{
                    if(mp[s.top()+i]){
                        s.push(i), any = 1, count++;
                        break;
                    }
                }
            }
            if(any == 0)
                break;
        }
        cout << count << endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
