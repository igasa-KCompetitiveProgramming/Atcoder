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
    vector<ll> x(n),y(n);
    rep(i,n){
        cin >> x[i] >> y[i];
    }
    vector<ll> x1,y1,x2,y2;
    rep(i,n){
        if((x[i]+y[i])%2==0){
            x2.push_back(x[i]+y[i]);
            y2.push_back(x[i]-y[i]);
        }else{
            x1.push_back(x[i]+y[i]);
            y1.push_back(x[i]-y[i]);
        }
    }
    sort(x1.begin(),x1.end());
    sort(x2.begin(),x2.end());
    sort(y1.begin(),y1.end());
    sort(y2.begin(),y2.end());
    ll ans = 0;
    rep(i,x1.size()){
        ans += x1[i]*(2*i-x1.size()+1);
        ans += y1[i]*(2*i-y1.size()+1);
    }
    rep(i,x2.size()){
        ans += x2[i]*(2*i-x2.size()+1);
        ans += y2[i]*(2*i-y2.size()+1);
    }
    cout << ans/2 << endl;
}