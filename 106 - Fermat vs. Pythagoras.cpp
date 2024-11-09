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
    ll n;
    while(cin >> n){
        vector<int> vtr(n+1);
        ll count1 = 0;
        for(ll i = 1; i*i <= n; i++){
            for(ll j = i+1; j*j <= n; j++){
                ll a = 2*i*j;
                ll b = j*j-i*i;
                ll c = j*j+i*i;
                if(__gcd(__gcd(a,b),c) == 1 && c <= n){
                    count1++;
                    int t = n/c;
                    for(int i = 1; i <= t; i++)
                        vtr[a*i]++, vtr[b*i]++, vtr[c*i]++;
                }
            }
        }
        int count2 = 0;
        for(int i = 1; i <= n; i++)
            if(vtr[i] == 0)
                count2++;
        cout << count1 << " " << count2 << endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
