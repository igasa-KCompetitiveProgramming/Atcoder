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
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<ll> u(m),v(m),b(m);
    map<ll,vector<pll>> mp;
    priority_queue<tuple<ll,ll,ll>, vector<tuple<ll,ll,ll>>, greater<tuple<ll,ll,ll>>> Q;
    rep(i,m){
        cin >> u[i] >> v[i] >> b[i];
        if(u[i] == 1){
            Q.push({b[i]+a[u[i]-1]+a[v[i]-1],u[i],v[i]});
        }else if(v[i] == 1){
            Q.push({b[i]+a[u[i]-1]+a[v[i]-1],v[i],u[i]});
        }else{
            mp[u[i]].push_back({v[i],b[i]});
            mp[v[i]].push_back({u[i],b[i]});
        }
    }
    vector<ll> ans(n,INF);
    ans[0] = 0;
    vector<bool> used(n,false);
    ll cost,now,next;
    vector<int> data;
    
    while(!Q.empty()){
        cost = get<0>(Q.top());
        now = get<1>(Q.top());
        next = get<2>(Q.top());
        Q.pop();
        if(used[next-1]) continue;
        ans[next-1] = min(ans[next-1],cost);
        used[next-1] = true;
        for(auto x:mp[next]){
            if(used[x.first-1]) continue;
            Q.push({ans[next-1]+x.second+a[x.first-1],next,x.first});
        }
    }
    rep(i,n-1){
        cout << ans[i+1] << " ";
    }
}