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
//bool compare(all_of(check.begin(), check.end(), [](bool x){return x;}))//全ての要素がtrueならtrueを返す
int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<vector<bool>> ans(n,vector<bool>(2,false));
    ans[0][0] = true;
    ans[0][1] = true;
    rep(i,n-1){
        if(ans[i][0]){
            if(fabs(a[i+1]-a[i])<=k){
                ans[i+1][0] = true;
            }
            if(fabs(b[i+1]-a[i])<=k){
                ans[i+1][1] = true;
            }
        }
        if(ans[i][1]){
            if(fabs(a[i+1]-b[i])<=k){
                ans[i+1][0] = true;
            }
            if(fabs(b[i+1]-b[i])<=k){
                ans[i+1][1] = true;
            }
        }
        if(!(ans[i][0]||ans[i][1])){
            cout << "No" << endl;
            return 0;
        }
    }
    if(!(ans[n-1][0]||ans[n-1][1])){
            cout << "No" << endl;
            return 0;
        }
    cout << "Yes" << endl;
}