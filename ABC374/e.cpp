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
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n),b(n),p(n),q(n);
    int e = 0;
    rep(i,n){
        cin >> a[i] >> p[i] >> b[i] >> q[i];
        e = max(a[i],b[i]);
    }
    ll left = -1;
    ll right = pow(10,7)*e + 1; // rightは各自設定
    while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
        ll mid = left + (right - left) / 2;
        ll sum = 0;

        if(x < sum){ //配列[mid]より比較対象が小さい場合
            right = mid;
        }else{
            left = mid;
        }
        if(right < left) break;
    }
    if(left == -1){
        cout << 0 << endl;
        return 0;
    }
    cout << left << endl;
}