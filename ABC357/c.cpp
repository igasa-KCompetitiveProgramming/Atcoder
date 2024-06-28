#include <bits/stdc++.h>
#include <fstream>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) outfile << "Yes" << endl; else outfile << "No" << endl 
#define YESNO(bool) if(bool) outfile << "YES" << endl; else outfile << "NO" << endl 
int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19
bool compare(pint& p1, pint& p2){return p1.second < p2.second;}
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
//bool compare(all_of(check.begin(), check.end(), [](bool x){return x;}))//全ての要素がtrueならtrueを返す
void saiki(vector<string> &ans,int n){
    if(n==1) return;
    n--;
    int size = ans[0].size();
    rep(i,size){
        ans[size+i] += ans[i];
        rep(j,size){
            ans[size+i].push_back('.');
        }
        ans[size+i] += ans[i];
    }
    rep(i,size){
        ans[i] += ans[i] + ans[i];
    }
    rep(i,size){
        ans[size*2+i] = ans[i];
    }
    saiki(ans,n);
}

int main(){
    int n;
    cin >> n;
    if(n == 0){
        cout << "#";
        return 0;
    }
    vector<string> s(pow(3,n));
    s[0] = "###";
    s[1] = "#.#";
    s[2] = "###";
    saiki(s,n);
    rep(i,pow(3,n)){
        cout << s[i] << endl;
    }
}