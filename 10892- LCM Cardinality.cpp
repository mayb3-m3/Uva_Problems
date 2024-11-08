#include <bits/stdc++.h>

#define imax INT_MAX
#define llmax INT64_MAX
#define ll long long
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
#define mod 1000000007
#define pie 3.141592653589793238
#define e_ 2.718281828459045235

using namespace std;

void solve(){
    while(1){
        ll n; cin >> n;
        if(n == 0)
            break;
        cout << n << " ";
        unordered_set<ll> st;
        for(ll i = 1; i*i <= n; i++)
            if(n%i == 0)
                st.insert(i), st.insert(n/i);
        vector<ll> vtr(st.begin(), st.end());
        ll count = 0, l = vtr.size();
        for(ll i = 0; i < l; i++)
            for(ll j = i+1; j < l; j++)
                if(vtr[i]*vtr[j]/__gcd(vtr[i],vtr[j]) == n)
                    count++;
        cout << count+1 << endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
