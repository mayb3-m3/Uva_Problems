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
vector<int> fr{1, 0, -1, 0};
vector<int> fc{0, 1, 0, -1};
int cnt = 0;

void dfs(int i, int j, int n){
    if(vtr[i][j] == 'x')
        cnt++;
    vtr[i][j] = '.';
    for(int k = 0; k < 4; k++){
        int x = i + fr[k];
        int y = j + fc[k];
        if(x >= 0 && y >= 0 && x < n && y < n && (vtr[x][y] == 'x' || vtr[x][y] == '@'))
            dfs(x, y, n);
    }
}
void solve(){
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        int n; cin >> n;
        vtr.assign(n, string());
        for(int i = 0; i < n; i++)
            cin >> vtr[i];
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(vtr[i][j] == 'x' || vtr[i][j] == '@'){
                    cnt = 0;
                    dfs(i, j, n);
                    if(cnt)
                        count++;
                }
            }
        }
        cout << "Case " << i << ": " << count << endl;
    }    
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
