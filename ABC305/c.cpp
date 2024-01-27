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
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h){
        cin >> s[i];
    }

    int minH = 0;
    bool first = true;
    vector<pint> side(h);
    rep(i,h){
        bool flag = true;
        rep(j,w){
            if(s[i][j]=='#'&&first){
                minH = i;
                first = false;
            }
            if(s[i][j]=='#'&&flag){
                side[i].first = j;
                flag = false;
            }else if(s[i][j]=='.'&&!flag){
                side[i].second = j;
                break;
            }else if(j==w-1&&s[i][j]=='#'){
                side[i].second = j+1;
            }
        }
        
    }

    if(side[minH].first>side[minH+1].first){
        cout << minH+1 << " " << side[minH].first;
        return 0;
    }else if(side[minH].second<side[minH+1].second){
        cout << minH+1 << " " << side[minH].first+2;
        return 0;
    }
    rep(i,h-1){
        if(side[i+minH].first<side[i+minH+1].first){
            cout << i+minH+2 << " " << side[i+minH+1].first;
            return 0;
        }else if(side[i+minH].second>side[i+minH+1].second){
            cout << i+minH+2 << " " << side[i+minH+1].second+1;
            return 0;
        }
    }
}