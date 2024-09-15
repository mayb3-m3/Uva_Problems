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
#define si size
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
#define next_p(x) next_permutation(x.begin(), x.end())
#define _rand(x,y) min(x,y)+rand()%(abs(y-x)+1)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pss pair<string, string>
#define psi pair<string, int>
#define pis pair<int, string>
#define pque priority_queue
#define umap unordered_map
#define uset unordered_set
#define ummap unordered_multimap
#define umset unordered_multiset
#define _mod 1000000007
#define _pie 3.141592653589793238
#define _e 2.718281828459045235

using namespace std;

bool func(vector<vector<int>> &vtr1, vector<int> &vtr2){
    bool ans = 1;
    if(vtr1.empty())
        return ans;
    for(auto v : vtr1){
        int a = 0, b = 0;
        for(int i = 0; i < int(vtr2.size()); i++){
            if(vtr2[i] == v[0])
                a = i;
            if(vtr2[i] == v[1])
                b = i;
        }
        if(v[2] > 0 && abs(b-a) > v[2])
            ans = 0;
        if(v[2] < 0 && abs(b-a) < -v[2])
            ans = 0;
    }
    return ans;
}
void solve(){
    while(1){
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0)
            break;
        vector<int> vtr;
        vector<vector<int>> t;
        for(int i = 0; i < a; i++)
            vtr.pub(i);
        for(int i = 0; i < b; i++){
            int x, y, z;
            cin >> x >> y >> z;
            t.pub({x, y, z});
        }
        int ans = 0;
        do{
            if(func(t, vtr))
                ans++;
        }while(next_p(vtr));  
        cout << ans << endl; 
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
