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
#define _e 2.718281828459045235

using namespace std;

void solve(){
    int lim = 1e3;
    vector<bool> vtr(lim+1, true);
    vtr[0] = false, vtr[1] = true;
    for(int i = 2; i*i <= lim; i++)
        if(vtr[i])
            for(int j = i*i; j <= lim; j += i)
                vtr[j] = false;
    vector<int> ans;
    for(int i = 0; i <= lim; i++)
        if(vtr[i])
            ans.push_back(i);
    int n, c;
    while(cin >> n >> c){
        cout << n << " " << c << ":";
        int count = 0;
        vector<int> ana;
        for(int i : ans){
            if(i > n)
                break;
            count++;
            ana.push_back(i);
        }
        if(count%2){
            if(count <= 2*c-1){
                for(int i : ana)
                    cout << " " << i;
            }else{
                int s = count/2-c+1;
                int e = count/2+c-1;
                for(int i = s; i <= e; i++)
                    cout << " " << ana[i];
            }
        }else{
            if(count <= 2*c){
                for(int i : ana)
                    cout << " " << i;
            }else{
                int s = count/2-c;
                int e = count/2+c-1;
                for(int i = s; i <= e; i++)
                    cout << " " << ana[i];
            }
        }
        cout << endl << endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
