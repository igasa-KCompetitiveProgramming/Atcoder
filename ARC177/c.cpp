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
int n;
vector<string> c;
const vector<int> dx = {1,0,-1,0};
const vector<int> dy = {0,1,0,-1};

int dijkstra(int sx,int sy,int gx,int gy,char target){
    vector<vector<int>> dp(n, vector<int>(n,inf));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> next;
    vector<vector<bool>> used(n, vector<bool>(n,false));
    dp[sx][sy] = 0;
    next.push({0,sx,sy});
    while(true){
        if(next.size() == 0){
            break;
        }
        int ax = get<1>(next.top());
        int ay = get<2>(next.top());
        next.pop();
        if(used[ax][ay]) continue;
        used[ax][ay] = true;
        rep(i,4){
            int nx = ax + dx[i];
            int ny = ay + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            int cost = 0;
            if(c[nx][ny] != target) cost = 1;
            if(dp[nx][ny] > dp[ax][ay] + cost){
                dp[nx][ny] = dp[ax][ay] + cost;
                next.push({dp[nx][ny],nx,ny});
            }
        }
    }  

    return dp[gx][gy];
}

int main(){
    cin >> n;
    c.resize(n);
    rep(i,n){
        cin >> c[i];
    }
    
    int ans = 0;
    ans += dijkstra(0,0,n-1,n-1,'R');
    ans += dijkstra(0,n-1,n-1,0,'B');

    cout << ans << endl;
}