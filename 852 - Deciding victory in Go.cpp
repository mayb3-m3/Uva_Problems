#include <bits/stdc++.h>
#define pii pair<int, int>
#define pss pair<string, string>
#define pis pair<int, string>
#define psi pair<string, int>

using namespace std;

vector<string> vtr(9);
vector<int> fr{1, 0, -1, 0};
vector<int> fc{0, 1, 0, -1};
int cnt, is_blk, is_wte;
void dfs(int r, int c){
    vtr[r][c] = '#';
    cnt++;
    for(int i = 0; i < 4; i++){
        int nr = r+fr[i], nc = c+fc[i];
        if(nr >= 0 && nr < 9 && nc >= 0 && nc < 9){
            if(vtr[nr][nc] == 'X')
                is_blk = true;
            else if(vtr[nr][nc] == 'O')
                is_wte = true;
            else if(vtr[nr][nc] == '.')
                dfs(nr, nc);
        }
    }
}

void solve(){
    int t; cin >> t;
    while(t--){
        int b_cnt = 0, w_cnt = 0;
        for(int i = 0; i < 9; i++){
            cin >> vtr[i];
            for(char ch : vtr[i]){
                if(ch == 'X') b_cnt++;
                if(ch == 'O') w_cnt++;
            }
        }
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(vtr[i][j] == '.'){
                    cnt = is_blk = is_wte = false;
                    dfs(i, j);
                    if(is_blk && !is_wte) b_cnt += cnt;
                    if(is_wte && !is_blk) w_cnt += cnt;
                }
            }
        }
        cout << "Black " << b_cnt << " White " << w_cnt << endl;
    }    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
