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
    ll t;
    cin >> t;
    vector<ll> n(t),k(t),m(t);
    rep(i,t){
        cin >> n[i] >> m[i] >> k[i];
    }
    vector<int> a = {6,2,4,8};
    rep(i,t){
        if(n[i]<m[i]){
            cout << a[n[i]%4] << endl;
            continue;
        }
        if(m[i]-k[i]==1){
            cout << 0 << endl;
            continue;
        }
        ll waru = (n[i]-m[i])/(m[i]-k[i])+1;
        ll tmp = n[i]-waru*(m[i]-k[i]);
        ll tmp2 = tmp%4;
        cout << a[tmp2] << endl;
    }
}