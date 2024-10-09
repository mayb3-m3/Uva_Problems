#include <bits/stdc++.h>

#define imax INT_MAX
#define llmax INT64_MAX
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
#define mod 1000000007
#define pie 3.141592653589793238
#define e_ 2.718281828459045235

using namespace std;

void solve(){
    while(1){
        int n, k;
        cin >> n >> k;
        if(n == -1 && k == -1)
            break;
        map<int, int> mp;
        bool zero = 0;
        for(int i = 0; i <= n; i++){
            int t; cin >> t;
            if(k){
                int a = i/k, pwr = i%k;
                if(a%2)
                    t = -t;
                mp[pwr] = mp[pwr]+t;
            }else
                zero = 1;
        }
        if(zero)
            cout << "0\n";
        else{
            int f = 1;
            for(auto i : mp){
                if(f)
                    cout << i.ss, f = 0;
                else
                    cout << " " << i.ss;
            }cout << endl;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
