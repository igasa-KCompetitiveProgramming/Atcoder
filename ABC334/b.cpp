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
    ll a,m,l,r;
    cin >> a >> m >> l >> r;
    l -= a;
    r -= a;
    ll ans = 0;
    if(l<0){
        ans -= l/m;
    }else{
        ans -= l/m;
    }
    if(r<0){
        ans += r/m;
    }else{  
        ans += r/m;
    }   

    if((l%m==0&&l>0)||(r%m==0&&r<0)||(l<=0&&r>=0)){
        cout << abs(ans) + 1 << endl;
    }else{
        cout << abs(ans) << endl;
    }
    
}