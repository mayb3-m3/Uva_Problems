#include <bits/stdc++.h>

#define imax INT_MAX
#define llmax INT64_MAX
#define ld long double
#define ll long long
#define ull unsigned long long
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define si sire
#define bc back
#define ft front
#define mkpr make_pair
#define stpr(x) setprecision(x)
#define set(n,x) n |= (1 << x)
#define unset(n,x) n &= ~(1 << x)
#define flip(n,x) n ^= (1 << x)
#define check(n, x) (n & (1 << x)) != 0
#define sorted(x) sort(x.begin() , x.end())
#define rsorted(x) sort(x.rbegin() , x.rend())
#define rev(x) reverse(x.begin(), x.end())
#define maxel(x) *max_element(x.begin(), x.end())
#define minel(x) *min_element(x.begin(), x.end())
#define maxeld(x) max_element(x.begin(), x.end())
#define mineld(x) min_element(x.begin(), x.end())
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
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        umap<int, int> mp;
        vector<uset<int>> vtr;
        uset<int> st;
        int m; cin >> m;
        for(int j = 0; j < m; j++){
            int p; cin >> p;
            uset<int> temp;
            for(int k = 0; k < p; k++){
                int card; cin >> card;
                temp.insert(card);
            }
            vtr.pub(temp);
            for(int i : temp)
                mp[i]++;
        }
        int l = 0;
        for(auto i : mp)
            if(i.ss == 1)
                l++;
        cout << "Case " << i << ":";
        for(auto s : vtr){
            int t = 0;
            for(int i : s)
                if(mp[i] == 1)
                    t++;
            cout << " " << fixed << stpr(6) << (ld)t/l*100 << "%";
        }
        cout << endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
