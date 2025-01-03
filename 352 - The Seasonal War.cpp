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

void dfs(int i, int j, int n){
    vtr[i][j] = '0';
    for(int k = 0; k < 8; k++){
        int x = i + fr[k], y = j + fc[k];
        if(x >= 0 && y >= 0 && x < n && y < n && vtr[x][y] == '1')
            dfs(x, y, n);
    }
}
void solve(){
    int n, t = 1;
    while(cin >> n){
        vtr.assign(n, string());
        for(int i = 0; i < n; i++)
            cin >> vtr[i];
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(vtr[i][j] == '1'){
                    dfs(i, j, n);
                    count++;
                }   
            }
        }
        cout << "Image number " << t++ << " contains " << count << " war eagles.\n";
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
