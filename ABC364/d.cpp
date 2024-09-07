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
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b(q),k(q);
    rep(i,q) cin >> b[i] >> k[i];
    sort(a.begin(),a.end());
    rep(i,q){
        int left = -1; // leftは各自設定
        int right = 2e8+10; // rightは各自設定
        while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
            int mid = left + (right - left) / 2;
            
            auto f = [&](int x) -> bool {
                // (# of points in [b-x, b+x]) >= k
                auto lb = lower_bound(a.begin(), a.end(), b[i] - x);
                auto ub = upper_bound(a.begin(), a.end(), b[i] + x);
                return ub - lb >= k[i];
            };

            
            //if(k[i] <= cnt){ //配列[mid]より比較対象が小さい場合
            if(f(mid)){
                right = mid;
            }else{
                left = mid;
            }
            if(right < left) break;
        }
        cout << right << endl;
    }
}