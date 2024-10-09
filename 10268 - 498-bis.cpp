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
    int sol, num;
    while(cin >> sol){
        cin.ignore();
        string str;
        getline(cin, str);
        vector<ll> vtr;
        stringstream ss(str);
        while(ss >> num)
            vtr.pub(num);
        ll l = vtr.size()-1, sum = 0;
        if(l == 0){
            cout << "0\n";
            continue;
        }
        vector<ll> res(l);
        res[0] = 1;
        for(int i = 1; i < l; i++)
            res[i] = res[i-1]*sol;
        rev(res);
        int p = l;
        for(ll i = 0; i < l; i++)
            sum += vtr[i]*res[i]*p--;
        cout << sum << endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
