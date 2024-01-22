#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
bool compare(pint& p1, pint& p2){return p1.second < p2.second;}
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
int main(){
    int n;
    cin >> n;
    int check[3] = {1,1,1};
    ll ans = 0;
    rep(i,n-1){
        if(check[0]==check[1]&&check[1]==check[2]) {
            check[2]++;
            check[1] = 1;
            check[0] = 1;
        }else if(check[1]==check[0]){
            check[1]++;
            check[0] = 1;
        }else{
            check[0]++;
        }
    }

    rep(i,3){
        rep(j,check[i]){
            ans += pow(10,j);
        }
    }

    cout << ans ;
}