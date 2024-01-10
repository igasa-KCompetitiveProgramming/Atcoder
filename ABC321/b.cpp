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
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    vector<int> b(n);
    int sum = 0;
    int ans = -1;
    rep(i,n-1) cin >> a[i];
    rep(i,101){
        sum = 0;
        a[n-1]=i;
        b = a;
        sort(b.begin(),b.end());
        rep(j,n-2){
            sum += b[j+1];
        }
        if(sum >= x){
            ans = i;
            break;
        }
    }
    cout << ans;
}