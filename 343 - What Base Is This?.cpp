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
#define mod 1000000007
#define pie 3.141592653589793238
#define _e 2.718281828459045235

using namespace std;

int mn_base(string str, unordered_map<char, int> mp){
    int mx = -1;
    for(char ch : str)
        mx = max(mx, mp[ch]);
    return max(2, mx+1);
}

int val(string str, unordered_map<char, int> mp, int n){
    int ans = 0, mul = 1;
    reverse(str.begin(), str.end());
    for(char ch : str){
        ans += mp[ch]*mul;
        mul *= n;
    }
    return ans;
}
void solve(){
    unordered_map<char, int> mp;
    for(char ch = '0'; ch <= '9'; ch++)
        mp[ch] = ch-48;
    for(char ch = 'A'; ch <= 'Z'; ch++)
        mp[ch] = ch-55;
    string s1, s2;
    while(cin >> s1 >> s2){
        int get = 0;
        int mn1 = mn_base(s1, mp);
        int mn2 = mn_base(s2, mp);
        for(int i = mn1; i <= 36; i++){
            for(int j = mn2; j <= 36; j++){
                int val1 = val(s1, mp, i);
                int val2 = val(s2, mp, j);
                if(val1 == val2){
                    cout << s1 << " (base " << i << ") = ";
                    cout << s2 << " (base " << j << ")\n";
                    get = 1, i = 36, j = 36;
                }
            }
        }
        if(get == 0)
            cout << s1 << " is not equal to " << s2 << " in any base 2..36\n";
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
