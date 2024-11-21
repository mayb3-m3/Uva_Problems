#include <bits/stdc++.h>

#define imax INT_MAX
#define llmax INT64_MAX
#define ll long long
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

void solve(){
    int lim = 1e6;
    vector<bool> vtr(lim+1, true);
    vtr[0] = vtr[1] = false;
    for(int i = 2; i*i <= lim; i++)
        if(vtr[i])
            for(int j = i*i; j <= lim; j += i)
                vtr[j] = false;
    while(1){
        int n; cin >> n;
        if(n == 0)
            break;
        int count = 0;
        for(int i = 2; i <= n/2; i++){
            if(vtr[i] && vtr[n-i])
                count++;
        }
        cout << count  << endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
