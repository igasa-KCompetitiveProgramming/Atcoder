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
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    rep(i,n){
        rep(j,i+1){
            cin >> a[i][j];
        }
    }
    int now = 1;
    rep(j,n){
        if(now >= j + 1){
            now = a[now-1][j];
        }else{
            now = a[j][now-1];
        }
    }
    cout << now;
}