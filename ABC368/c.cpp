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
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    ll t = 0;
    int mod = 0;
    rep(i,n){
        if(mod == 1){
            h[i]--;
            mod = 2;
            t++;
            if(h[i] == 0){
                continue;
            }
        }
        if(mod == 2){
            h[i] -= 3;
            mod = 0;
            t++;
            if(h[i] <= 0){
                continue;
            }
        }
        if(mod == 0){
            mod = h[i] % 5;
            t += (h[i] / 5)*3;
            h[i] = h[i] % 5;
            if(h[i] == 0){
                continue;
            }else if(h[i] > 2){
                h[i] = 0;
                mod = 0;
                t += 3;
            }else{
                t += h[i];
                mod = h[i];
                h[i] = 0;
            }
        }
        if(mod > 2){
            mod = 0;
        }
    }
    cout << t << endl;
}