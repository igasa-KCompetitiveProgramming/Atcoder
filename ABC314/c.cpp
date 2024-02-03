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
int main(){
    int n,m;
    string s;
    cin >> n >> m;
    cin >> s;
    vector<int> c(n);
    vector<vector<int>> p(m);
    rep(i,n){
        cin >> c[i];
        p[c[i]-1].push_back(i);
    }

    string ans(n,'0');
    rep(i,m){
        rep(j,p[i].size()){
            if(j!=0){
                ans[p[i][j]] = s[p[i][j-1]];
            }else{
                ans[p[i][0]] = s[p[i][p[i].size()-1]];
            }
        }
    }

    cout << ans << endl;
}