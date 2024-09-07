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
    int n;
    cin >> n;
    vector<int> a(n);
    int l = 0;
    int r = 0;
    int ans = 0;
    rep(i,n){
        char c;
        cin >> a[i] >> c;
        if(c == 'R'){
            if(r == 0){
                r = a[i];
            }else{
                ans += abs(r-a[i]);
                r = a[i];
            }
        }else{
            if(l == 0){
                l = a[i];
            }else{
                ans += abs(l-a[i]);
                l = a[i];
            }
        }
    }
    cout << ans << endl;
}