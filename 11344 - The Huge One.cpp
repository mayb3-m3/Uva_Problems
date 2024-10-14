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

bool wonderful(string str, unordered_set<int> st){
    vector<int> rem(13, 0);
    for(char ch : str)
        for(int i : st)
            rem[i] = (rem[i]*10 + ch-'0')%i;
    bool ans = 1;
    for(int i : st)
        if(rem[i])
            ans = 0;
    return ans;
}
    
void solve(){
    int t; cin >> t;
    while(t--){
        string str;
        cin >> str;
        int n; cin >> n;
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            int el; cin >> el;
            st.insert(el);
        }
        if(wonderful(str, st))
            cout << str << " - Wonderful.\n";
        else
            cout << str << " - Simple.\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
