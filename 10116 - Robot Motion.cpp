#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
void steps(vector<string> vtr, pii s, pii d, int& cnt){
    cnt++;
    char ch = vtr[s.first][s.second];
    if(ch == 'N') s.first--;
    else if(ch == 'S') s.first++;
    else if(ch == 'E') s.second++;
    else if(ch == 'W') s.second--;
    if(s == d)
        return;
    steps(vtr, s, d, cnt);
}
void solve(){
    while(true){
        int r, c, s;
        cin >> r >> c >> s;
        if(r+c+s == 0)
            break;
        s--;
        vector<string> vtr(r);
        for(int i = 0; i < r; i++)
            cin >> vtr[i];
        vector<string> change(vtr);
        int count = 0, loop = false, i = 0, j = s;
        pii start;
        while(1){
            count++;
            change[i][j] = '#';
            if(vtr[i][j] == 'N') i--;
            else if(vtr[i][j] == 'S') i++;
            else if(vtr[i][j] == 'E') j++;
            else if(vtr[i][j] == 'W') j--;
            if(i < 0 || j < 0 || i >= r || j >= c)
                break;
            if(change[i][j] == '#'){
                loop = true, start = {i, j};
                break;
            }
        }
        if(loop){
            int cnt = 0;
            steps(vtr, start, start, cnt);
            cout << count-cnt << " step(s) before a loop of " << cnt << " step(s)\n";
        }else
            cout << count << " step(s) to exit\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
