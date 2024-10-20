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
    int a, b, st = 1;
    while(cin >> a >> b){
        vector<int> vtr(2*a);
        for(int i = 0; i < b; i++)
            cin >> vtr[i];
        double avrg = accumulate(vtr.begin(), vtr.end(), 0)/double(a), ans = 0;
        sorted(vtr);
        cout << "Set #" << st++ << endl;
        for(int i = 0; i < a; i++){
            cout << " " << i << ":";
            int j = 2*a-i-1;
            if(vtr[i])
                cout << " " << vtr[i];
            if(vtr[j])
                cout << " " << vtr[j];
            cout << endl;
            ans += abs(avrg - (vtr[i]+vtr[j]));
        }
        cout << fixed << stpr(5) << "IMBALANCE = " << ans << endl << endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
