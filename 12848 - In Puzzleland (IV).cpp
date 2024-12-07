#include <bits/stdc++.h>
#define ll long long
#define imax INT_MAX
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

void solve() {
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        int a, b, c;
        cin >> a >> b >> c;
        a--, c--;
        if((b*c) % a == 0){
            cout << b*c/a << endl;
        }else{
            if(b*c >= a){
                cout << b*c/a << " ";
                int g = __gcd(b*c%a, a);
                cout << (b*c%a)/g << "/" << a/g << endl;
            }else{
                int g = __gcd(b*c, a);

                cout << b*c/g << "/" << a/g << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
