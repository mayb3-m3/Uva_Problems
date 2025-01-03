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

vector<string> vtr;
vector<int> fr{1, 1, 0, -1, -1, -1, 0, 1};
vector<int> fc{0, 1, 1, 1, 0, -1, -1, -1};
int cnt = 0;

void dfs(int i, int j, int n, int m){
    vtr[i][j] = '0';
    cnt++;
    for(int k = 0; k < 8; k++){
        int x = i + fr[k], y = j + fc[k];
        if(x >= 0 && y >= 0 && x < n && y < m && vtr[x][y] == '1')
            dfs(x, y, n, m);
    }
}
void solve(){
    int t; cin >> t;
    cin.ignore();
    cin.ignore();
    for(int i = 1; i <= t; i++){
        vtr.clear();
        string str;
        while(getline(cin, str)){
            if(str.empty())
                break;
            vtr.push_back(str);
        }
        int n = vtr.size();
        int m = vtr[0].size();
        int mx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vtr[i][j] == '1'){
                    cnt = 0;
                    dfs(i, j, n, m);
                    mx = max(mx, cnt);
                }
            }
        }
        cout << mx << endl;
        if(i < t)
            cout << endl;
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
