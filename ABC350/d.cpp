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
    ll n,m;
    cin >> n >> m;
    vector<ll> a(m),b(m);
    vector<vector<ll>> friendList(n);
    rep(i,m){
        cin >> a[i] >> b[i];
        friendList[a[i]-1].push_back(b[i]-1);
        friendList[b[i]-1].push_back(a[i]-1);
    }
    vector<bool> seen(n,false);
    vector<ll> bondNum;
    rep(i,n){
        if(seen[i]) continue;
        vector<ll> check;
        seen[i] = true;
        ll cnt = 0;
        cnt++;
        check.push_back(i);
        while(true){
            if(check.size()==0){
                bondNum.push_back(cnt);
                break;
            }
            seen[i] = true;
            ll now = check[check.size()-1];
            check.pop_back();
            for(auto x: friendList[now]){
                if(seen[x]) continue;
                seen[x] = true;
                check.push_back(x);
                cnt++;
            }
        }
    }
    ll ans = 0;
    rep(i,bondNum.size()){
        ans += bondNum[i]*(bondNum[i]-1)/2;
    }
    ans -= m;
    cout << ans << endl;
}