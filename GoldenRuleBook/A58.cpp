#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define rep1(i,n) for (ll i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19
bool compare(pint& p1, pint& p2){return p1.second < p2.second;}
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
//bool compare(all_of(check.begin(), check.end(), [](bool x){return x;}))//全ての要素がtrueならtrueを返す

class SegmentTree {
    ll length = 2;
    vector<ll> node;
public:
    SegmentTree(ll len){
        len--;
        ll tmp = 1;
        while(true){
            if(len == 0) break;
            len /= 2;
            tmp *= 2;
            length += tmp;
        }
        rep(i,length){
            node.push_back(0);
        }
        cout << node.size() << endl;
    }

    SegmentTree(ll n, ll x){

    }
};

int main(){
    SegmentTree st(17);

    return 0;
}
