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
    int k,g,m;
    int g1 =0;
    int m1 =0;
    cin >> k >> g >> m;
    rep(i,k){
        if(g1 == g){
            g1 = 0;
        }else if(m1 == 0){
            m1 = m;
        }else{
            if(g1+m1>g){
                m1 = m1 - (g - g1);
                g1 = g;
            }else{
                g1 += m1;
                m1 = 0;
            }
        }
    }
    cout << g1 << " " << m1;
}