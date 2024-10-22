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
    vector<int> x(n),y(n);
    rep(i,n){
        cin >> x[i] >> y[i];
    }
    double ans = 0;
    int nx = 0, ny = 0;
    rep(i,n){
        ans += sqrt((x[i]-nx)*(x[i]-nx) + (y[i]-ny)*(y[i]-ny));
        nx = x[i];
        ny = y[i];
    }
    ans += sqrt(nx*nx + ny*ny);
    cout << setprecision(15) << ans << endl;
}