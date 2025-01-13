#include <bits/stdc++.h>
#define pii pair<int, int>
#define pss pair<string, string>

using namespace std;

string space_removed(string str){
    string ans;
    for(char ch : str)
        if(ch != ' ')
            ans += ch;
    return ans;
}
void solve(){
    int t; cin >> t;
    cin.ignore();
    for(int i = 1; i <= t; i++){
        string str1, str2;
        getline(cin, str1);
        getline(cin, str2);
        cout << "Case " << i << ": ";
        if(str1 == str2){
            cout << "Yes\n";
        }else{
            string spaceless = space_removed(str1);
            if(spaceless == str2)
                cout << "Output Format Error\n";
            else
                cout << "Wrong Answer\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
