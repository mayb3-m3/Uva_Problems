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
pis func(ll n, ll ml){
    string str(to_string(n));
    ll l = str.size();
    str = string(ml-l, '0')+str;
    ll n1 = stoi(str.substr(0, ml/2));
    ll n2 = stoi(str.substr(ml/2));
    if((n1+n2)*(n1+n2) == n)
        return {1, str};
    else
        return {0, ""};
}
void solve(){
    vector<ll> vtr;
    for(ll i = 0; i <= 1e4; i++)
        vtr.push_back(i*i);
    ll n;
    while(cin >> n){
        ll cap = 99;
        if(n == 4) cap = 9999;
        if(n == 6) cap = 999999;
        if(n == 8) cap = 99999999;
        for(ll i : vtr){
            if(i > cap)
                break;
            else{
                pis t = func(i, n);
                if(t.first)
                    cout << t.second << endl; 
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
