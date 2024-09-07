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
    int h,w,q;
    cin >> h >> w >> q;
    vector<vector<bool>> mp1(h,vector<bool>(w,0));
    vector<vector<int>> mp(h,vector<int>(w,-1));
    vector<int> height(h,0);
    vector<int> width(w,0);
    vector<int> r(q),c(q);
    rep(i,q){
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    } 
    rep(i,q){
        int y = r[i];
        int x = c[i];
        if(mp1[y][x] == 0){
            mp1[y][x] = 1;
            height[y]++;
            width[x]++;
            continue;
        }else{
            mp[y][x]++;
        }
        int tmp;
        if(height[y] != w){
            tmp = x + mp[y][x];
            while(true){
                tmp++;
                if(tmp >= w) break;
                if(mp1[y][tmp] == 0){
                    mp1[y][tmp] = 1;
                    height[y]++;
                    width[tmp]++;
                    break;
                }
            }
            tmp = x - mp[y][x];
            while(true){
                tmp--;
                if(tmp < 0) break;
                if(mp1[y][tmp] == 0){
                    mp1[y][tmp] = 1;
                    height[y]++;
                    width[tmp]++;
                    break;
                }
            }
        }
        if(width[x] != h){
            tmp = y + mp[y][x];
            while(true){
                tmp++;
                if(tmp >= h) break;
                if(mp1[tmp][x] == 0){
                    mp1[tmp][x] = 1;
                    height[tmp]++;
                    width[x]++;
                    break;
                }
            }
            tmp = y - mp[y][x];
            while(true){
                tmp--;
                if(tmp < 0) break;
                if(mp1[tmp][x] == 0){
                    mp1[tmp][x] = 1;
                    height[tmp]++;
                    width[x]++;
                    break;
                }
            }
        }
    }
    int ans = 0;
    rep(i,h){
        ans += w-height[i];
    }
    cout << ans;
}