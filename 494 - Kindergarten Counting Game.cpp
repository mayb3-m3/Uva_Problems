#include <bits/stdc++.h>
using namespace std;

void solve(){
    string str;
    while(getline(cin, str)){
        string t;
        str += " ";
        int count = 0;
        for(char ch : str){
            if(isalpha(ch)){
                t += ch;
            }else{
                if(!t.empty())
                    count++;
                t.clear();
            }
        }
        cout << count << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
