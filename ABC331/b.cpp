#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
int inf = 1410065408;
int main(){
    int n,s,m,l;
    cin >> n >> s >> m >> l;
    int ans = inf;
    rep(i,20){
        rep(j,18){
            rep(k,12){
                if(i*6+j*8+k*12>=n){
                    ans = min(ans,i*s+j*m+k*l);
                }
            }
        }
    }
    cout << ans << endl;
}