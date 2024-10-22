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
    string s;
    cin >> s;
    ll ans = 0;
    rep(i,26){
        char c;
        ll sum = 0;
        ll cnt = 0;
        c = 'A' + i;
        ll nx = 0;
        rep(j,s.size()){
            if(s[j] == c){
                ans += sum;
                if(cnt != 0){
                    ans += (j - nx)*cnt - 1;
                    sum += (j - nx)*cnt - 1;
                }
                cout << c << " " << j << " " << sum << " " << ans << endl;
                cnt++;
                nx = j;
            }
        }
    }
    cout << ans << endl;

}