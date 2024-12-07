#include <bits/stdc++.h>
#define ll long long
#define imax INT_MAX
#define pll pair<ll, ll>
using namespace std;

void solve() {
    int a, b, c;
    while(cin >> a >> b >> c){
        int ans;
        for(int i = 4; i <= 50; i++){
            int val = i*(i+1)/2 + (i-a)*(i-a+1)/2 - 9;
            if(val == b+c){
                ans = b - (i*(i+1)/2 - 6);
                break;
            }
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
