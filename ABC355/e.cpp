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
    int n,l,r;
    cin >> n >> l >> r;
    int ans = 0;
    int nowL = l;
    while(true){
        int x = nowL;
        int y = r;
        if(nowL == r){
            cout << "!" << ans % 100;
            return 0;
        }else{
            int cnt = 0;
            while(true){
                if(x%2==0){
                    x /= 2;
                    cnt++;
                }else{
                    break;
                }
            }
            int minCnt = abs(y-(pow(2,cnt)*(x+1)-1));
            int I = cnt;
            int J = x;
            rep(i,cnt){
                x = nowL;
                int tmp = abs(y-(pow(2,i)*(x+1)-1));
                if(tmp > minCnt){
                    continue;
                }else{
                    I = i;
                    J = x;
                    minCnt = tmp;
                }
                nowL /= 2;
            }
            cout << nowL << " ";
            nowL += abs(pow(2,I)*(J+1) - pow(2,I)*J);
            cout << abs(pow(2,I)*(J+1) - pow(2,I)*J) << " " << nowL << endl;
            cout << "? " << I << " " << J << endl;
            int t;
            cin >> t;
            ans += t;
            ans %= 100;
        }
    }
}