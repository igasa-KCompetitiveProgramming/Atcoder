#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
bool compare(pint& p1, pint& p2){return p1.second < p2.second;}
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
int main(){
    int n,q;
    string s;
    int l[300000],r[300000];
    int sum[300000];
    int ans = 0;
    cin >> n >> q;
    cin >> s;
    rep(i,q){
        cin >> l[i] >> r[i];
    }

    sum[0] = 0;
    rep1(i,n){
        if(s[i-1]==s[i]){
            ans++;
            sum[i] = ans;
        }else{
            sum[i] = ans;
        }
    }

    rep(i,q){
        cout << sum[r[i]-1]-sum[l[i]-1] << endl;
    }
}