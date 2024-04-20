#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
bool compare(pint& p1, pint& p2){return p1.second < p2.second;}
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
int main(){
    ll n,q;
    cin >> n >> q;
    vector<ll> r(n);
    vector<ll> sum(n);
    vector<ll> query(q);
    rep(i,n){
        cin >> r[i];
    }
    rep(i,q){
        cin >> query[i];
    }
    sort(r.begin(),r.end());
    sum[0] = r[0];
    rep(i,r.size()-1){
        sum[i+1] = sum[i] + r[i+1];
    }
    rep(i,q){
        ll mid = sum.size()/2;
        ll left = -1;
        ll right = sum.size(); // rightは各自設定
        while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
            int mid = left + (right - left) / 2;
            if(sum[mid] > query[i]){ //配列[mid]より比較対象が小さい場合
                right = mid;
            }else{
                left = mid;
            }
            if(right < left) break;
        }
        cout << right << endl;
    }
}