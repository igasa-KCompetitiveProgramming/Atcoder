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
    string s,t;
    cin >> s >> t;
    map<char,int> mpS;
    map<char,int> mpT;
    int checkS = 0;
    int checkT = 0;
    rep(i,26){
        mpS['a'+i] = 0;
    }
    rep(i,26){
        mpT['a'+i] = 0;
    }
    rep(i,s.size()){
        if(s[i]=='@') checkS++;
        else mpS[s[i]]++;
    }
    rep(i,t.size()){
        if(t[i]=='@') checkT++;
        else mpT[t[i]]++;
    }
    char atcoder[7] = {'a','t','c','o','d','e','r'};
    sort(atcoder,atcoder+7);
    int check = 0;
    rep(i,26){
        if('a'+i==atcoder[check]){
            if(mpS['a'+i]<mpT['a'+i]){
                checkS -= mpT['a'+i]-mpS['a'+i];
            }else if(mpS['a'+i]>mpT['a'+i]){
                checkT -= mpS['a'+i]-mpT['a'+i];
            }
            check++;
        }else if(mpS['a'+i]!=mpT['a'+i]){
            cout << "No" << endl;
            return 0;
        }
    }
    if(checkS<0||checkT<0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}