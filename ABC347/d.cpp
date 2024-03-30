#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19
bool compare(pint& p1, pint& p2){return p1.second < p2.second;}
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
//bool compare(all_of(check.begin(), check.end(), [](bool x){return x;}))//全ての要素がtrueならtrueを返す
int main(){
    int a,b;
    ull c;
    cin >> a >> b >> c;
    bitset<60> c1(c);
    bitset<60> ans1;
    bitset<60> ans2;
    rep(i,60){
        if(c1[i]){
            if(a>b){
                ans1[i] = 1;
                a--;
            }else if(b>a){
                ans2[i] = 1;
                b--;
            }else{
                ans1[i] = 1;
                a--;
            }
        }
    }
    rep(i,60){
        if(a>0){
            if(c1[i]==0){
                ans1[i] = 1;
                ans2[i] = 1;
                a--;
                b--;
            }
        }
    }
    if(a!=0 || b!=0){
        cout << -1;
        return 0;
    }
    cout << ans1.to_ullong() << " " << ans2.to_ullong();
}