#include <bits/stdc++.h>

#define imax INT_MAX
#define llmax INT64_MAX
#define ll long long
#define sorted(x) sort(x.begin() , x.end())
#define rsorted(x) sort(x.rbegin() , x.rend())
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

int ham(string s1, string s2){
    int ans = 0;
    for(int i = 0; i < int(s1.size()); i++)
        if(s1[i] != s2[i])
            ans++;
    return ans;
}
void solve(){
    int a, b;
    cin >> a >> b;
    vector<string> vtr(a);
    for(int i = 0; i < a; i++)
        cin >> vtr[i];
    for(int i = 0; i < b; i++){
        string str;
        cin >> str;
        int ans = 1, mn = imax;
        for(int j = 0; j < a; j++){
            int l1 = str.size(), l2 = vtr[j].size();
            if(l2 >= l1){
                for(int k = 0; k <= l2-l1; k++){
                    string temp = vtr[j].substr(k, l1);
                    int t = ham(temp, str);
                    if(t < mn)
                        mn = t, ans = j+1;
                }
            }
        }
        cout << ans << endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
