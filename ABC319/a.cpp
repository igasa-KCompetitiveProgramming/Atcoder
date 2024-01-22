#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
bool compare(pint& p1, pint& p2){return p1.second < p2.second;}
bool compare(pll& p1, pll& p2){return p1.second < p2.second;}//secondの値でfirstをsort
//bool compare(all_of(check.begin(), check.end(), [](bool x){return x;}))//全ての要素がtrueならtrueを返す
int main(){
    string s;
    cin >> s;
    if(s=="tourist"){
        cout << 3858 << endl;
    }
    if(s=="ksun48"){
        cout << 3679 << endl;
    }
    if(s=="Benq"){
        cout << 3658 << endl;
    }
    if(s=="Um_nik"){
        cout << 3648 << endl;
    }
    if(s=="apiad"){
        cout << 3638 << endl;
    }
    if(s=="Stonefeang"){
        cout << 3630 << endl;
    }
    if(s=="ecnerwala"){
        cout << 3613 << endl;
    }
    if(s=="mnbvmar"){
        cout << 3555 << endl;
    }
    if(s=="newbiedmy"){
        cout << 3516 << endl;
    }
    if(s=="semiexp"){
        cout << 3481 << endl;
    }
}