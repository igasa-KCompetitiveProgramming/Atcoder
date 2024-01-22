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
int main(void){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    int l=0;
    int ans=0;
    rep(i,n){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    rep(i,n){
        if(a[i]-a[l]+1>m){
            while(a[i]-a[l]>m){
                l++;
            }
            if(a[i]-a[l]==m) l++;
            ans = max(ans, i-l+1);
        }else{
            ans = max(ans, i-l+1);
        }
    }
    cout << ans;

}