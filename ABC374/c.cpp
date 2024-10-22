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
    vector<int> a(n);
    bitset<20> b;
    rep(i,n){
        cin >> a[i];
    }
    ll ans = INF;
    rep(i,pow(2,n)){
        b = i;
        ll sum = 0;
        ll sum2 = 0;
        rep(j,n){
            if(b[j]){
                sum += a[j];
            }else{
                sum2 += a[j];
            }
        }
        ans = min(ans,max(sum,sum2));
    }
    cout << ans << endl;
}