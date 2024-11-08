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

void solve(){
    while(1){
        int first;
        cin >> first;
        if(first == 0)
            break;
        int ans = 0;
        while(1){
            int num;
            cin >> num;
            if(num == 0)
                break;
            else
                ans = __gcd(ans, abs(first-num));
        }
        cout << ans << endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
