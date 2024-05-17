#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19
bool compare(pint& p1, pint& p2){return p1.second < p2.second;}
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
//bool compare(all_of(check.begin(), check.end(), [](bool x){return x;}))//全ての要素がtrueならtrueを返す
int main(){
    int n;
    cin >> n;
    vector<ull> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    ull ans = 0;
    rep(i,n){
        ans += a[i] * (n-1);
    }
    ll tmp = pow(10,8);
    for(int i = n-1;i >= 1;i--){
        int mid;
        int left = -1;
        int right = i-1; // rightは各自設定
        mid = left + (right - left) / 2;
        while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
            int mid = left + (right - left) / 2;
            if(tmp <= a[i] + a[mid]){ //配列[mid]より比較対象が小さい場合
                right = mid;
            }else{
                left = mid;
            }
            if(right < left) break;
        }
        if(a[i]+a[right] >= tmp) ans -= tmp*(i-right);
        else break;
    }
    cout << ans << endl;
}