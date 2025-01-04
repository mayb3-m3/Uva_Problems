#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<int>& nums, int idx, int tot) {
    if (idx == 5)
        return tot == 23;
    return dfs(nums, idx + 1, tot + nums[idx]) ||
           dfs(nums, idx + 1, tot - nums[idx]) ||
           dfs(nums, idx + 1, tot * nums[idx]);
}

void solve(){
    while(true){
        vector<int> v(5);
        for (int i = 0; i < 5; i++) 
            cin >> v[i];
        if (v[0]+v[1]+v[2]+v[3]+v[4] == 0)
            break;
        sort(v.begin(), v.end());
        bool possible = false;
        do{
            if(dfs(v, 1, v[0])){
                possible = true;
                break;
            }
        }while (next_permutation(v.begin(), v.end()));

        if(possible)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
