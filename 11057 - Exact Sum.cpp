#include <bits/stdc++.h>
#define imax INT_MAX
#define llmax INT64_MAX
#define ll long long
#define ull unsigned long long
#define _rand(x,y) min(x,y)+rand()%(abs(y-x)+1)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pss pair<string, string>
#define psi pair<string, int>
#define pis pair<int, string>
#define pie 3.141592653589793238
#define _e 2.718281828459045235

using namespace std;

void solve(){
    int n; 
    while(cin >> n){
        vector<int> vtr(n);
        for(int i = 0; i < n; i++)
            cin >> vtr[i];
        int val; cin >> val;
        sort(vtr.begin(), vtr.end());
        int l = 0, r = n-1, lv, rv;
        while(l < r){
            int sum = vtr[l]+vtr[r];
            if(sum == val){
                lv = vtr[l], rv = vtr[r];
                l++, r--;
            }else if(sum < val)
                l++;
            else
                r--;
            
        }
        cout << "Peter should buy books whose prices are " << lv << " and " << rv << ".\n\n";
    }    
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
