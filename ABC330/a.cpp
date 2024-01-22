#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
int main(){
    int n, l;
    int a[1000];
    cin >> n >> l;
    int ans = 0;
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        if(a[i]>=l){
            ans++;
        }
    }
    cout << ans;
}