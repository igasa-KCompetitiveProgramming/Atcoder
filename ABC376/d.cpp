#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19
int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> a(m),b(m);
    vector<vector<ll>> g(n+1);
    rep(i,m){
        cin >> a[i] >> b[i];
        g[a[i]].push_back(b[i]);
    }
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    rep(i,n) sort(g[i+1].begin(),g[i+1].end());
    rep(i,g[1].size()){
        pq.push({1,g[1][i]});
    }
    while(true){
        if(pq.size() == 0){
            break;
        }
        ll cost = get<0>(pq.top());
        ll now = get<1>(pq.top());
        pq.pop();
        if(now == 1){
            cout << cost << endl;
            return 0;
        }
        rep(i,g[now].size()){
            pq.push({cost+1,g[now][i]});
        }
    }
    cout << -1 << endl;
}