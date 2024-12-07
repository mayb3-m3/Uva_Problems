#include <bits/stdc++.h>
#define ll long long
#define imax INT_MAX
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

void solve() {
    int n; 
    while(cin >> n){
        vector<int> v1, v2;
        int x = n+1, count = 0;
        while(1){
            if(n*x % (x-n) == 0){
                int y = n*x / (x-n);
                v1.push_back(y);
                v2.push_back(x);
                count++;
                if(x == y)
                    break;
            }
            x++;
        }
        cout << count << endl;
        for(int i = 0; i < count; i++){
            cout << "1/" << n << " = ";
            cout << "1/" << v1[i] << " + ";
            cout << "1/" << v2[i] << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
