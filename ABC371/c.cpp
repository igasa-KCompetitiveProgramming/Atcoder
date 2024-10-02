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
    int n,g,h;
    cin >> n >> g;
    vector<int> u(g),v(g);
    vector<vector<bool>> G(n,vector<bool>(n));
    rep(i,g){
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
        G[u[i]][v[i]] = true;
        G[v[i]][u[i]] = true;
    }
    cin >> h;
    vector<int> a(h),b(h);
    vector<vector<bool>> H(n,vector<bool>(n));
    rep(i,h){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        H[a[i]][b[i]] = true;
        H[b[i]][a[i]] = true;
    }
    vector<vector<int>> cost(n,vector<int>(n,-1)); 
    rep(i,n-1){
        rep(j,n-i-1){
            cin >> cost[i][j+i+1];
            cost[j+i+1][i] = cost[i][j+i+1];
        }
    }
    rep(i,n){
        rep(j,n){
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
    rep(i,n){
        rep(j,n){
            cout << H[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> tmp(n);
    rep(i,n){
        tmp[i] = i;
    }
    int ans = inf;
    while(true){
        int kari = 0;
        int cnt = 0;
        rep(i,n){
            rep(j,n){
                if(G[i][j] != H[tmp[i]][tmp[j]]){
                    kari += cost[i][j];
                    cnt++;
                }
            }
        }
        cout << cnt << " ";
        ans = min(ans,kari);
        if(!next_permutation(tmp.begin(),tmp.end())) break;
    }
    cout << ans;
}