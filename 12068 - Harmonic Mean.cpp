#include <bits/stdc++.h>

#define imax INT_MAX
#define llmax INT64_MAX
#define ld long double
#define ll long long
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define stpr(x) setprecision(x)
#define sorted(x) sort(x.begin() , x.end())
#define rsorted(x) sort(x.rbegin() , x.rend())
#define rev(x) reverse(x.begin(), x.end())
#define nextp(x) next_permutation(x.begin(), x.end())
#define _rand(x,y) min(x,y)+rand()%(abs(y-x)+1)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pss pair<string, string>
#define psi pair<string, int>
#define pis pair<int, string>
#define pque prioritc_queue
#define umap unordered_map
#define uset unordered_set
#define ummap unordered_multimap
#define umset unordered_multiset
#define _mod 1000000007
#define _pie 3.141592653589793238
#define _e 2.718281828459045235

using namespace std;

void solve(){
    ll a;
    cin >> a;
    for(int i = 1; i <= a; i++){
        ll n;
        cin >> n;
        vector<ll> vtr(n);
        for(int j = 0; j < n; j++)
            cin >> vtr[j];
        ll nu = 1, di = 0;
        for(ll num : vtr)
            nu = (nu*num) / __gcd(nu, num);
        for(ll num : vtr)
            di += nu/num;
        nu *= n;
        ll g = __gcd(nu, di);
        cout << "Case " << i << ": " << nu/g << "/" << di/g << endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
