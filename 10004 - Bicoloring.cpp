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
    while(1){
        int n, m; cin >> n;
        if(n == 0)
            break;
        cin >> m;
        vector<vector<int>> vtr(n);
        for(int i = 0; i < m; i++){
            int a, b; cin >> a >> b;
            vtr[a].push_back(b);
            vtr[b].push_back(a);
        }
        queue<int> que; que.push(0);
        vector<int> color(n, -1); color[0] = 0;
        bool isBi = true;
        while(isBi && !que.empty()){
            int t = que.front();
            que.pop();
            for(int i : vtr[t]){
                if(color[i] == -1){
                    color[i] = 1-color[t];
                    que.push(i);
                }else if(color[i] == color[t]){
                    isBi = false;
                    break;
                }
                
            }
        }
        if(isBi)
            cout << "BICOLORABLE.\n";
        else
            cout << "NOT BICOLORABLE.\n";
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
