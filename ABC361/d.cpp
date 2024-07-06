#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19
bool compare(pint& p1, pint& p2){return p1.second < p2.second;}
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
//bool compare(all_of(check.begin(), check.end(), [](bool x){return x;}))//全ての要素がtrueならtrueを返す

int n;
string t;

int dfs(vector<tuple<string,int,int>> s){
    if(t == get<0>(s)) return get<2>(s);
    else{
        int ans = inf;
        rep(i,n+1){
            if(s[i] == '.'){
                i += 2;
            }
            swap(s[i],s[num]);
            swap(s[i+1],s[num+1]);
            cout << s << endl;
            int tmp = dfs(s,cnt+1,num);
            if(tmp < 0) continue;
            ans = min(ans,tmp);
        }
    }
}

int main(){
    int n;
    string s,t;
    cin >> n;
    cin >> s >> t;
    s.append("..");
    t.append("..");
    vector<tuple<string,int,int>> start = {make_tuple(s,0,n)};
    cout << dfs(start) << endl;
}