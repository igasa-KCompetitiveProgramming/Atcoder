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
int bfs(ll cnt, ll n, vector<vector<ll>>& friends, vector<vector<ll>>& ans, vector<bool>& seen,vector<ll>& check){
    ll x = check[0];
    check.erase(check.begin());
    seen[x] = true;
    if(ans[cnt][ans[cnt].size()-1]!=x) ans.push_back({x});
    rep(i,friends[x].size()){
        if(seen[friends[x][i]]){
            continue;
        }else{
            ans[cnt].push_back(friends[x][i]);
            seen[friends[x][i]] = true;
            check.push_back(friends[x][i]);
        }
    }
    if(check.empty()){
        return 0;
    }else{
        bfs(cnt,n,friends,ans,seen,check);
        return 0;
    }
}

int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> a(m),b(m);
    vector<vector<ll>> friends(n);
    rep(i,m){
        cin >> a[i];
        cin >> b[i];
        friends[a[i]-1].push_back(b[i]-1);
    }
    vector<vector<ll>> ans(n+m);
    vector<bool> seen(n,false);
    vector<ll> check;
    ll cnt = 0;
    check.push_back(0);
    rep(i,n){
        if(seen[i]){
            continue;
        }else{
            check.push_back(i);
            ans[cnt].push_back(i);
            bfs(cnt,n,friends,ans,seen,check);
            cnt++;
        }
    }
    ll ans1 = 0;
    rep(i,cnt){
        ans1 += ans[i].size()*(ans[i].size()-1)/2; 
    }
    ans1 -= m;
    cout << ans1;
}