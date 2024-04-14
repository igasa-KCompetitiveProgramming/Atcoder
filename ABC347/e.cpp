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
    ll n,q;
    cin >> n >> q;
    vector<ll> x(q);
    rep(i,q) cin >> x[i];
    vector<ll> add(q+1);
    vector<vector<ll>> point(n);
    map<ll,ll> mp;
    add[0] = 0;
    rep(i,q){
        point[x[i]-1].push_back(i+1);
        if(mp[x[i]] == 0) mp[x[i]]++;
        else mp.erase(x[i]);
        add[i+1] = add[i] + mp.size();
    }
    vector<ll> ans(n);
    rep(i,n){
        rep(j,point[i].size()/2){
            ans[i] += add[point[i][2*j+1]-1] - add[point[i][2*j]-1];
        }
        if(point[i].size()%2 == 1) ans[i] += add[q] - add[point[i][point[i].size()-1]-1];
    }
    rep(i,n){
        cout << ans[i] << " ";
    }
}