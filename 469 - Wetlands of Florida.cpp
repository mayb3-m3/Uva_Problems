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
vector<int> fr{1, 1, 0,-1,-1,-1, 0, 1};
vector<int> fc{0, 1, 1, 1, 0,-1,-1,-1};
void flood_fill(int y, int x, int r, int c, int& count){
    if(y < 0 || y >= r || x < 0 || x >= c || vtr[y][x] != 'W')
        return;
    vtr[y][x] = 'L';
    count++;
    for(int i = 0; i < 8; i++)
        flood_fill(y+fr[i], x+fc[i], r, c, count);
}
void solve(){
    int t; cin >> t;
    cin.ignore();
    cin.ignore();
    for(int i = 1; i <= t; i++){
        vtr.clear();
        vector<pii> query;
        while(1){
            string str;
            getline(cin, str);
            if(str.empty())
                break;
            else if(str[0] == 'W' || str[0] == 'L')
                vtr.push_back(str);
            else{
                stringstream ss(str);
                int a, b;
                ss >> a >> b;
                query.push_back({a-1, b-1});
            }
        }
        vector<string> temp(vtr);
        int r = vtr.size(), c = vtr[0].size();
        for(auto p : query){
            vtr = temp;
            int count = 0;
            flood_fill(p.first, p.second, r, c, count);
            cout << count << endl;
        }
        if(i != t)
            cout << endl;
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
