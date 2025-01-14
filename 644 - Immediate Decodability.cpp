#include <bits/stdc++.h>
#define pii pair<int, int>
#define pss pair<string, string>

using namespace std;

int is_decodable(vector<string> v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && v[i].size() <= v[j].size()){
                if(v[i] == v[j].substr(0, v[i].size()))
                    return false;
            }
        }
    }
    return true;
}
void solve(){
    int st = 1;
    vector<string> vtr;
    while(true){
        string str; cin >> str;
        if(cin.eof())
            break;
        if(str == "9"){
            if(is_decodable(vtr))
                cout << "Set " << st++ << " is immediately decodable\n";
            else
                cout << "Set " << st++ << " is not immediately decodable\n";
            vtr.clear();
        }else
            vtr.push_back(str); 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
