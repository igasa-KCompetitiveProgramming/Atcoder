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
    int n,m;
    cin >> n >> m;
    vector<int> u(m),v(m),w(m);
    vector<vector<pint>> g(n);
    rep(i,m){
        cin >> u[i] >> v[i] >> w[i];
        u[i]--; v[i]--;
        g[u[i]].push_back({v[i],-1*w[i]});
        g[v[i]].push_back({u[i],w[i]});
    }
    vector<ll> ans(n);
    vector<bool> used(n,false);
    queue<int> q;
    rep(i,n){
        if(used[i]) continue;
        q.push(i);
        used[i] = true;
        ans[i] = 0;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(pint next : g[now]){
                if(used[next.first]) continue;
                used[next.first] = true;
                q.push(next.first);
                ans[next.first] = ans[now] - next.second;
            }
        }
    }
    rep(i,n){
        cout << ans[i] << " ";
    }
}