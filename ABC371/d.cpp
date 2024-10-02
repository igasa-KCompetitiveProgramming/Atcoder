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
    vector<ll> x(n);
    vector<ll> p(n);
    vector<ll> ruiseki(n+1);
    ruiseki[0] = 0;
    rep(i,n){
        cin >> x[i];
    }
    rep(i,n){
        cin >> p[i];
        ruiseki[i+1] = ruiseki[i] + p[i];
    }
    int q;
    cin >> q;
    vector<ll> l(q),r(q);
    rep(i,q){
        cin >> l[i] >> r[i];
    }
    rep(i,q){
        ll left = -1;
        ll right = n; // rightは各自設定
        while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
            ll mid = left + (right - left) / 2;
            if(x[mid] >= l[i]){ //配列[mid]より比較対象が小さい場合
                right = mid;
            }else{
                left = mid;
            }
            if(right < left) break;
        }
        ll tmp = ruiseki[left+1];
        left = -1;
        right = n; // rightは各自設定
        while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
            ll mid = left + (right - left) / 2;
            //cout << mid << " " << x[mid] << " " << r[i] << endl;
            if(x[mid] >= r[i]){ //配列[mid]より比較対象が小さい場合
                right = mid;
            }else{
                left = mid;
            }
            if(right < left) break;
        }
        if(x[right] == r[i]) left++;
        cout << ruiseki[left+1] - tmp << endl; 
    }
}