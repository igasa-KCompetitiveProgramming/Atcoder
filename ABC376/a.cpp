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
    int n,c;
    cin >> n >> c;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    int ans = 1;
    int now = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] - now >= c){
            now = a[i];
            ans++;
        }
    }
    cout << ans << endl;
}