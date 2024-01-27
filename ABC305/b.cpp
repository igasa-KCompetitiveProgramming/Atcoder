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
    char p,q;
    cin >> p >> q;
    if(p>q){
        swap(p,q);
    }
    int dx[7] = {0,3,4,8,9,14,23};
    int dy[7] = {23,20,19,15,14,9,0};
    int max = 23;
    rep(i,6){
        if(p-'A'==i){
            max -= dx[i];
            break;
        }
    }
    rep(i,6){
        if(q-'A'==6-i){
            max -= dy[6-i];
            break;
        }
    }
    cout << max << endl;
}