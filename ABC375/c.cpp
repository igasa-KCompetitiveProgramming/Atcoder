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
    vector<string> a(n);
    vector<string> ans(n);
    rep(i,n){
        cin >> a[i];
        rep(j,n){
            ans[i] += ' ';
        }
    }
    rep(i,n){
        rep(j,n){
            int tmp = min(abs(n-i-1),i);
            int res = min(abs(n-j-1),j);
            tmp = min(tmp,res);
            if((tmp+1) % 4 == 0){
                ans[i][j] = a[i][j];
            }else if((tmp+1) % 4 == 1){
                ans[j][n-i-1] = a[i][j];
            }else if((tmp+1) % 4 == 2){
                ans[n-i-1][n-j-1] = a[i][j];
            }else if((tmp+1) % 4 == 3){
                ans[n-j-1][i] = a[i][j];
            }
        }
    }
    rep(i,n){
        cout << ans[i] << endl;
    }
}