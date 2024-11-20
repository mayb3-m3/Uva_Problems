#include <bits/stdc++.h>

#define imax INT_MAX
#define llmax INT64_MAX
#define ll long long
#define _rand(x,y) min(x,y)+rand()%(abs(y-x)+1)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pss pair<string, string>
#define psi pair<string, int>
#define pis pair<int, string>
#define mod 1000000007
#define pie 3.141592653589793238
#define e_ 2.718281828459045235

using namespace std;

bool comp1(pair<string, pii> a, pair<string, pii> b){
    return a.first < b.first;
}bool comp2(pair<string, pii> a, pair<string, pii> b){
    return a.second.first > b.second.first;
}bool comp3(pair<string, pii> a, pair<string, pii> b){
    return a.second.second < b.second.second;
}
void print(vector<pair<string, pii>> v, int s){
    vector<string> vtr;
    for(int i = s; i < s+5; i++)
        vtr.push_back(v[i].first);
    sort(vtr.begin(), vtr.end());
    cout << "(";
    for(int i = 0; i < 4; i++)
        cout << vtr[i] << ", ";
    cout << vtr.back() << ")\n";
}

void solve(){
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        vector<pair<string, pii>> vtr(10);
        for(int i = 0; i < 10; i++){
            string s;
            int n1, n2;
            cin >> s >> n1 >> n2;
            vtr[i] = {s, {n1, n2}};
        }
        cout << "Case " << i << ":\n";
        sort(vtr.begin(), vtr.end(), comp1);
        sort(vtr.begin(), vtr.end(), comp3);
        sort(vtr.begin(), vtr.end(), comp2);
        print(vtr, 0);
        print(vtr, 5);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
