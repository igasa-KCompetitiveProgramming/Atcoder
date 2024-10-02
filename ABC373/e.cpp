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

int permitationCheck(vector<ll> c, ll y){
    int left = -1;
    int right = c.size()-1; // rightは各自設定
    while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
        int mid = left + (right - left) / 2;
        if(c[mid] >= y){ //配列[mid]より比較対象が小さい場合
            right = mid;
        }else{
            left = mid;
        }
        if(right < left) break;
    }
    return right;
}

int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(n),b(n),c(m+1);
    rep(i,n){
        cin >> a[i];
        b[i] = a[i];
        k -= a[i];
    }
    sort(b.rbegin(),b.rend());
    vector<ll> ruiseki(m+2,0);
    map<ll,ll> mp;
    rep(i,m+1){
        ruiseki[i+1] = ruiseki[i] + b[m-i];
        c[m-i] = b[i];
        mp[a[m-i]]++;
    }
    rep(i,n){
        ll left = -1;
        ll right = k+1; // rightは各自設定
        while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
            ll mid = left + (right - left) / 2;

            int res = permitationCheck(c, a[i] + mid);

            if(c[res] == a[i] + mid){
                res--;
            }

            if(res < 0){
                left = mid;
            }else if(res*(a[i] + mid) - ruiseki[res] - (k - mid) >= 0){ //配列[mid]より比較対象が小さい場合
                right = mid;
            }else{
                left = mid;
            }
            if(right < left) break;
        }
        if(right == k+1) cout << -1 << " ";
        else cout << right << " ";
    }
}