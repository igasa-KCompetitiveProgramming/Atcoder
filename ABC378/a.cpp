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
    vector<int> a(4);
    map<int,int> mp;
    rep(i,4){
        cin >> a[i];
        mp[a[i]]++;
    }
    int ans = 0;
    for(auto x:mp){
        ans += x.second/2;
    }
    cout << ans;
}