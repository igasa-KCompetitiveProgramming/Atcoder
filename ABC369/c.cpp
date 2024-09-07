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
    ll n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    vector<int> a(n);
    vector<int> ruiseki(n-1,0);
    rep(i,n){
        cin >> a[i];
        if(i != 0){
            ruiseki[i-1] = a[i] - a[i-1];
        }
    }
    ll ans = 0;
    ll cnt = 1;
    rep(i,n-2){
        if(ruiseki[i] == ruiseki[i+1]){
            cnt++;
        }else{
            ans += (cnt+1)*cnt/2;
            cnt = 1;
        }
    }
    ans += (cnt+1)*cnt/2;
    ans += n;
    cout << ans << endl;
}