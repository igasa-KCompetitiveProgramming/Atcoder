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
    int a[100];
    int b[100];
    int c[100];
    int d[100];
    int ans[100][100] = {};
    int ans1=0;
    cin >> n;
    rep(i,n){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    rep(i,n){
        for(int j=a[i];j<b[i];j++){
            for(int k=c[i];k<d[i];k++){
                ans[j][k]++;
            }
        }
    }

    rep(i,100){
        rep(j,100){
            if(ans[i][j]>0){
                ans1++;
            }
        }
    }
    cout << ans1;
}