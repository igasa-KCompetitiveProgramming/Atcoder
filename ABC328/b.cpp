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
    int d[100];
    int ans = 0;
    cin >> n;
    rep(i,n){
        cin >> d[i];
    }

    rep1(i,n){
        rep1(j,d[i-1]){
            if(i<10){
                if(j==i||j==i*11){
                    ans++;
                }
            }else if(i%11==0){
                if(j==i||(j==i/11&&i%11==0)){
                    ans++;
                }
            }
        }
    }
    cout << ans;
}