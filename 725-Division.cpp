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

bool func(int n1, int n2){
    vector<bool> vtr(10);
    string str(to_string(n1)+to_string(n2));
    if((int)str.size() <= 9)
        str += "0";
    for(char ch : str)
        vtr[ch-'0'] = 1;
    int ans = 1;
    for(bool i : vtr)
        if(i == 0)
            ans = 0;
    return ans;
}
void solve(){
    int a = 0;
    while(1){
        int n;
        cin >> n;
        if(n == 0)
            break;
        if(a)
            cout << endl;
        a++;
        int t = 1;
        for(int i = 1234*n; i <= 98765; i++){
            if(i % n == 0){
                int ans = func(i, i/n);
                if(ans){
                    t = 0;
                    if(i <= 9999)
                        cout << 0;
                    cout << i << " / ";
                    if(i/n <= 9999)
                        cout << 0;
                    cout << i/n << " = " << n << endl;
                }
            }
        }
        if(t)
            cout << "There are no solutions for " << n << ".\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
