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
//bool compare(all_of(check.begin(), check.end(), [](bool x){return x;}))//全ての要素がtrueならtrueを返す
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    sort(a.rbegin(),a.rend());

    ll sum = 0;
    rep(i,n){
        sum += a[i];
    }

    ll ave = sum/n;
    ll rem = sum%n;
    ll ans = 0;

    rep(i,n){
        if(i>=rem){
            if(a[i]-ave>0){
                ans += a[i]-ave;
            }else{
                break;
            }
        }else{
            if(a[i]-1-ave>0){
                ans += a[i]-ave-1;
            }else{
                break;
            }
        }
    }

    if(n==1){
        cout << 0 << endl;
    }
    else{
        cout << ans << endl;
    }
}