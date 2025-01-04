#include <bits/stdc++.h>
using namespace std;

void solve(){
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        int n, h; cin >> n >> h;
        string str = string(n-h, '0') + string(h, '1');
        do{
            cout << str << endl;
        }while(next_permutation(str.begin(), str.end()));
        if(i < t)
            cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
