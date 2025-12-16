#include <bits/stdc++.h>
using namespace std;
 
#define inf 1e15
#define ll long long
#define pl pair<ll, ll>
#define vl vector<ll>
#define vd vector<double>
#define mod 1000000007
// #define mod 998244353
#define pie 3.141592653589793238
#define _e 2.718281828459045235
#define LSOne(i) ((i) & -(i))

ll val(const string& str, ll x, ll N){
    stack<ll> stc;
    stringstream ss(str);
    string token;

    while (ss >> token){
        if (token == "x") stc.push(x);
        else if (token == "N") stc.push(N);
        else if (token == "+" || token == "*" || token == "%"){
            ll b = stc.top(); stc.pop();
            ll a = stc.top(); stc.pop();
            if(token == "+") stc.push((a+b) % N);
            else if(token == "*") stc.push((a*b) % N);
            else stc.push(a%b);
        }else {
            stc.push(stoll(token) % N);
        }
    }
    return stc.top() % N;
}

 
void solve(){
    // ll t = 1;
    //cin >> t;
    while(true){
        // freopen("badmilk.in", "r", stdin);
        // freopen("badmilk.out", "w", stdout);
 
        string expr, func;
        getline(cin, expr);
        if(expr == "0 0 0 N %") break;

        string token;
        stringstream ss(expr);
        ss >> token;
        ll N = stoll(token);
        ss >> token;
        ll x = stoll(token);
        while(ss >> token) func += token + " ";

        unordered_map<ll, ll> pos;
        ll cnt = 0;

        while(pos.count(x) == 0){
            pos[x] = cnt++;
            x = val(func, x, N);
        }

        cout << cnt - pos[x] << endl; 
    } 
 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
