#include <bits/stdc++.h>
using namespace std;

vector<string> vtr;
int h, w, cnt = 0;
vector<int> fr{0, 1, 0, -1};
vector<int> fc{1, 0, -1, 0};

void dfs(int a, int b){
    if(vtr[a][b] == 'G')
        cnt++;
    vtr[a][b] = '#';
    bool is_trap = false;
    for(int i = 0; i < 4; i++)
        if(vtr[a + fr[i]][b + fc[i]] == 'T')
            is_trap = true;
    if(is_trap)
        return;
    for(int i = 0; i < 4; i++){
        int x = a + fr[i];
        int y = b + fc[i];
        if(x >= 0 && y >= 0 && x < h && y < w && vtr[x][y] != '#')
            dfs(x, y);
    }
}
void solve(){
    while(cin >>  w >> h){
        vtr.assign(h, string());
        cnt = 0;
        for(int i = 0; i < h; i++)
            cin >> vtr[i];
        int a, b;
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                if(vtr[i][j] == 'P')
                    a = i, b = j;
        dfs(a, b);
        cout << cnt << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
