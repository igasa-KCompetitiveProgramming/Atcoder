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
    int a,b;
    cin >> a >> b;
    int c = -500;
    int ans = 0;
    rep(i,1000){
        if(a-c == b-a || b-c == a-b){
            ans++;
        }else if(c-b == a-c || c-a == b-c){
            ans++;
        }else if(b-a == c-b || a-b == c-a){
            ans++;
        }
        c++;
    }
    cout << ans << endl;
}