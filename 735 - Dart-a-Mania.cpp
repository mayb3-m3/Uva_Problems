#include <bits/stdc++.h>

#define imax INT_MAX
#define llmax INT64_MAX
#define ll long long
#define sorted(x) sort(x.begin() , x.end())
#define rsorted(x) sort(x.rbegin() , x.rend())
#define nextp(x) next_permutation(x.begin(), x.end())
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

void solve(){
    while(1){
        int n; cin >> n;
        if(n <= 0){
            cout << "END OF OUTPUT\n";
            break;
        }
        set<int> st{50};
        for(int i = 0; i <= 20; i++)
            st.insert(i), st.insert(i*2), st.insert(i*3);
        vector<int> vtr(st.begin(), st.end());
        set<set<int>> ans;
        int c1 = 0, c2 = 0, si = vtr.size();
        for(int i = 0; i < si; i++){
            for(int j = 0; j < si; j++){
                if(st.find(n-vtr[i]-vtr[j]) != st.end()){
                    set<int> temp{vtr[i], vtr[j], n-vtr[i]-vtr[j]};
                    int size = temp.size();
                    if(ans.find(temp) == ans.end()){
                        c1++;
                        ans.insert(temp);
                        if(size == 1)
                            c2 += 1;
                        else if(size == 2)
                            c2 += 3;
                        else    
                            c2 += 6;
                    }
                }
            }
        }
        if(c1 == 0)
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n";
        else{
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << c1 << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << c2 << ".\n";
        }
        cout << "**********************************************************************\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
