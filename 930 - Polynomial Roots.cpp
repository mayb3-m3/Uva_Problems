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

vector<ld> func(vector<ld> vtr, ld sol){
    vector<ld> ans;
    ans.pub(vtr[0]);
    ld t = vtr[0], l = vtr.size();
    for(ld i = 1; i < l; i++){
        t *= sol;
        t += vtr[i];
        ans.pub(t);
    }
    ans.pob();
    return ans;
}
void solve(){
    ld t; cin >> t;
    while(t--){
        ld n; cin >> n;
        vector<ld> vtr1(n+1), vtr2(n-2);
        for(ld i = 0; i <= n; i++)
            cin >> vtr1[i];
        for(ld i = 0; i < n-2; i++)
            cin >> vtr2[i];
        for(ld i : vtr2)
            vtr1 = func(vtr1, i);
        double x1 = -vtr1[1] + sqrt(vtr1[1]*vtr1[1] - 4*vtr1[0]*vtr1[2]);
        double x2 = -vtr1[1] - sqrt(vtr1[1]*vtr1[1] - 4*vtr1[0]*vtr1[2]);
        x1 /= 2*vtr1[0], x2 /= 2*vtr1[0];
        printf("%.1lf\n%.1lf\n", max(x1,x2), min(x1,x2));
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
