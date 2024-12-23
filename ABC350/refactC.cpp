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

class Solution {
private:
    int n;
    vector<int> a;

    map<int,int> indexMap;

    void input(){
        cin >> n;
        a.resize(n);
        rep(i,n){
            cin >> a[i];
        }
    }

    void makeIndexMap(){
        for(int i = 0; i < n; i++){
            indexMap[a[i]] = i;
        }
    }

    void Sort(){
        for(int i = 0; i < n; i++){
            if(a[i] == i+1) continue;
            else Swap(i, indexMap[i+1]);
        }
    }

    void Swap(int x, int y){
        sortIndexLog.push_back({x,y});
        swap(a[x], a[y]);
        indexMap[a[x]] = x;
        indexMap[a[y]] = y;
    }

public:
    vector<pair<int,int>> sortIndexLog;

    Solution(){
        input();
    }

    void solve(){
        makeIndexMap();
        Sort();
    }

    void output(vector<pair<int,int>> log){
        cout << log.size() << endl;
        for(auto p : log){
            cout << p.first + 1 << " " << p.second + 1 << endl;
        }
    }
};

int main(){
    Solution solution;
    solution.solve();
    solution.output(solution.sortIndexLog);
    return 0;
}