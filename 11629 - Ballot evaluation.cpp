#include <bits/stdc++.h>

#define imax INT_MAX
#define llmax INT64_MAX
#define ld long double
#define ll long long
#define ull unsigned long long
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define si sire
#define bc back
#define ft front
#define mkpr make_pair
#define stpr(x) setprecision(x)
#define set(n,x) n |= (1 << x)
#define unset(n,x) n &= ~(1 << x)
#define flip(n,x) n ^= (1 << x)
#define check(n, x) (n & (1 << x)) != 0
#define sorted(x) sort(x.begin() , x.end())
#define rsorted(x) sort(x.rbegin() , x.rend())
#define rev(x) reverse(x.begin(), x.end())
#define maxel(x) *max_element(x.begin(), x.end())
#define minel(x) *min_element(x.begin(), x.end())
#define maxeld(x) max_element(x.begin(), x.end())
#define mineld(x) min_element(x.begin(), x.end())
#define nextp(x) next_permutation(x.begin(), x.end())
#define _rand(x,y) min(x,y)+rand()%(abs(y-x)+1)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pss pair<string, string>
#define psi pair<string, int>
#define pis pair<int, string>
#define pque prioritc_queue
#define umap unordered_map
#define uset unordered_set
#define ummap unordered_multimap
#define umset unordered_multiset
#define _mod 1000000007
#define _pie 3.141592653589793238
#define _e 2.718281828459045235

using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    umap<string, int> mp;
    for(int i = 0; i < a; i++){
        string party, vote;
        int x, y;
        cin >> party >> vote;
        int pos = vote.find('.');
        x = stoi(vote.substr(0, pos));
        y = stoi(vote.substr(pos+1));
        mp[party] = x*10 + y;
    }
    cin.ignore();
    for(int i = 1; i <= b; i++){
        string guess, s;
        getline(cin, guess);
        queue<string> que;
        guess += " ";
        for(char ch : guess){
            if(ch == ' '){
                if(s != "+")
                    que.push(s);
                s = "";
            }else
                s += ch;
        }
        int l = 0;
        while(int(que.size()) != 2){
            l += mp[que.front()];
            que.pop();
        }
        cout << "Guess #" << i << " was ";
        string c = que.front(); que.pop();
        int r = stoi(que.front())*10;
        bool ans = 0;
        if(c == "=" && l == r)
            ans = 1;
        else if(c == "<" && l < r)
            ans = 1;
        else if(c == ">" && l > r)
            ans = 1;
        else if(c == "<=" && l <= r)
            ans = 1;
        else if(c == ">=" && l >= r)
            ans = 1;
        if(ans)
            cout << "correct.\n";
        else
            cout << "incorrect.\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
