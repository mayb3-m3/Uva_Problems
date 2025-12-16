#include <bits/stdc++.h>
using namespace std;
 
#define inf 1e15
#define ll long long
#define pl pair<ll, ll>
#define vl vector<ll>
#define vd vector<double>
#define mod 1000000007
// #define mod 998244353
#define pie 3.141592653589793238
#define _e 2.718281828459045235
#define LSOne(i) ((i) & -(i))

 
void solve(){
    ll t = 1;
    //cin >> t;
    while(true){
        // freopen("badmilk.in", "r", stdin);
        // freopen("badmilk.out", "w", stdout);
 
        ll z, i, m, l; cin >> z >> i >> m >> l;
        if(z == 0 && i == 0 && m == 0 && l == 0) break;

        set<ll> store;

        while(store.count(l) == 0){
            store.insert(l);
            l = (z*l + i) % m;
        }

        ll ans = 1, beg = l;
        while(true){
            l = (z*l + i) % m;
            if(l == beg) break;
            ans++;
        }

        cout << "Case " << t++ << ": " << ans << endl; 
    } 
 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
