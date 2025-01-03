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

vector<vector<int>> visited;
vector<vector<int>> value;
vector<int> fr;
vector<int> fc;

void dfs(int r, int c, int row, int col){
    visited[r][c] = 1;
    value[r][c] = 0;
    for(int i = 0; i < 8; i++){
        int x = r + fr[i];
        int y = c + fc[i];
        if(x >= 0 && x < row && y >= 0 && y < col && visited[x][y] == -1)
            dfs(x, y, row, col);
    }
}
void solve(){
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        int r, c, d1, d2;
        cin >> r >> c >> d1 >> d2;
        visited.assign(r, vector<int>(c, -1));
        value.assign(r, vector<int>(c, -1));
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            int a, b; cin >> a >> b;
            visited[a][b] = 1;
        }
        fr.assign({d1, d1, d2, d2, -d1, -d1, -d2, -d2});
        fc.assign({d2, -d2, d1, -d1, d2, -d2, d1, -d1});
        dfs(0, 0, r, c);
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                unordered_set<int> st;
                for(int k = 0; k < 8; k++){
                    if(value[i][j] == -1)
                        break;
                    int x = i + fr[k];
                    int y = j + fc[k];
                    if(x >= 0 && x < r && y >= 0 && y < c && value[x][y] != -1){
                        int pos = r*x + y;
                        if(st.find(pos) == st.end())
                            value[x][y]++, st.insert(r*x + y);
                    }
                }
            }
        }
        int odd = 0, even = 0;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(value[i][j] >= 0)
                    value[i][j] % 2 ? odd++ : even++;
        cout << "Case " << i << ": " << even << " " << odd << endl;
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
