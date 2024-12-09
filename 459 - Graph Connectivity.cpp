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
#define mod 1000000007
#define pie 3.141592653589793238
#define _e 2.718281828459045235

using namespace std;

vector<int> visited(1e3+5);
vector<vector<int>> vtr(1e3+5);

void dsf(int node){
    visited[node] = 1;
    for(int i : vtr[node]){
        if(!visited[i])
            dsf(i);
    }
}
void solve(){
    int t, first = 1; cin >> t;
    while(t--){
        if(!first)
            cout << endl;
        first = 0;
        visited.assign(1e3+5, 0);
        vtr.assign(1e3+5, vector<int>());
        char ch; cin >> ch;
        cin.ignore();
        int size = ch-'A';
        while(1){
            string s;
            getline(cin, s);
            if(s.empty())
                break;
            vtr[s[0]-'A'].push_back(s[1]-'A');
            vtr[s[1]-'A'].push_back(s[0]-'A');
        }
        int count = 0;
        for(int i = 0; i <= size; i++){
            if(!visited[i]){
                count++;
                dsf(i);
            }
        }
        cout << count << endl;
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
