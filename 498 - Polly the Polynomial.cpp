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

vector<ll> func(string str){
    vector<ll> ans;
    stringstream ss(str);
    ll num;
    while (ss >> num)
        ans.pub(num);
    return ans;
}
void solve(){
    string str1, str2;
    while(getline(cin, str1)){
        getline(cin, str2);
        int var = 0;
        vector<ll> vtr1 = func(str1), vtr2 = func(str2);
        int n = vtr1.size();
        for(ll i : vtr2){
            vector<ll> vtr(n);
            vtr[0] = 1;
            for(int j = 1; j < n; j++)
                vtr[j] = vtr[j-1]*i;
            ll sum = 0;
            for(int j = 0; j < n; j++)
                sum += vtr1[j]*vtr[n-j-1];
            if(var)
                cout << " ";
            var++;
            cout << sum;
        }
        cout << endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
