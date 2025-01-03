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

vector<int> fr{-1, -1, 0, 0, 1, 1};
vector<int> fc{-1, 0, -1, 1, 0, 1};
vector<string> vtr;
vector<vector<int>> state;
bool found = false;

void dfs(int r, int c, int mr, int mc){
    state[r][c] = 1;
    for(int i = 0; i < 6; i++){
        int x = r + fr[i];
        int y = c + fc[i];
        if(x >= 0 && x < mr && y >= 0 && x < mc){
            if(vtr[x][y] == 'b' && state[x][y] == -1){
                dfs(x, y, mr, mc);
            }else if(vtr[x][y] == 'B' && state[x][y] == -1)
                found = true;
        }
    }
}

void solve(){
    int t = 0;
    while(++t){
        int n; cin >> n;
        if(n == 0)
            break;
        vtr.assign(n, string());
        for(int i = 0; i < n; i++)
            cin >> vtr[i];
        for(int i = 0; i < n; i++)
            if(vtr[i][n-1] == 'w')
                vtr[i][n-1] = 'W';
        for(int i = 0; i < n; i++)
            if(vtr[n-1][i] == 'b')
                vtr[n-1][i] = 'B';
        bool ans = false;
        for(int i = 0; i < n; i++){
            found = false;
            state.assign(n, vector<int>(n, -1));
            if(vtr[0][i] == 'b')
                dfs(0, i, n, n);
            if(found == true){
                ans = true;
                break;
            }
        }
        if(ans)
            cout << t << " B\n";
        else
            cout << t << " W\n";
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
