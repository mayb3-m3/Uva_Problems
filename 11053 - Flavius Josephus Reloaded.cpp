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
    // ll t = 1;
    //cin >> t;
    while(true){
        // freopen("badmilk.in", "r", stdin);
        // freopen("badmilk.out", "w", stdout);
 
        ll N, a, b; cin >> N;
        if(N == 0) break;
        
        cin >> a >> b;
        unordered_map<ll, ll> pos;
        ll cnt = 0, x = b % N;

        while(pos.count(x) == 0){
            pos[x] = cnt++;
            x = (((a*x)%N)*x + b) % N;
        }
        
        cout << N - cnt + pos[x] << endl;;
    } 
 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
