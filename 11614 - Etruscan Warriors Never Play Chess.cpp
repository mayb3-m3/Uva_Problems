#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    int t; cin >> t;
    while(t--){
        long double n; cin >> n;
        long double ans = (-1 + sqrtl(1+8*n)) / 2;
        cout << (ll)ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
