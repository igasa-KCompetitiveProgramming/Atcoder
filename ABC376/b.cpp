#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19
int main(){
    int n,q;
    cin >> n >> q;
    vector<char> h(q);
    vector<int> t(q);
    rep(i,q){
        cin >> h[i] >> t[i];
    }
    int ans = 0;
    pint now = {2,1};
    rep(i,q){
        if(h[i] == 'R'){
            int cnt = 0;
            int pr = now.first;
            while(true){
                if(pr == 0) pr = n;
                else if(pr == n+1) pr = 1;
                if(pr == t[i]){
                    break;
                }else if(pr == now.second){
                    cnt = 100000;
                    break;
                }else pr--;
                cnt++;
            }
            int cnt2 = 0;
            swap(now.first,pr);
            while(true){
                if(pr == 0) pr = n;
                else if(pr == n+1) pr = 1;
                if(pr == t[i]){
                    break;
                }else if(pr == now.second){
                    cnt2 = 100000;
                    break;
                }else pr++;
                cnt2++;
            }
            ans += min(cnt,cnt2);
            if(cnt > cnt2){
                now.first = pr;
            }
        }else{
            int cnt = 0;
            int pl = now.second;
            while(true){
                if(pl == 0) pl = n;
                else if(pl == n+1) pl = 1;
                if(pl == t[i]){
                    break;
                }else if(pl == now.first){
                    cnt = inf;
                    break;
                }else pl++;
                cnt++;
            }
            int cnt2 = 0;
            swap(now.second,pl);
            while(true){
                if(pl == 0) pl = n;
                else if(pl == n+1) pl = 1;
                if(pl == t[i]){
                    break;
                }else if(pl == now.first){
                    cnt2 = inf;
                    break;
                }else pl--;
                cnt2++;
            }
            ans += min(cnt,cnt2);
            if(cnt > cnt2){
                now.second = pl;
            }
        }
    }
    cout << ans << endl;
}