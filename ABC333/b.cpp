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
int main(){
    char s[2];
    char t[2];
    cin >> s[0] >> s[1];
    cin >> t[0] >> t[1];
    bool check = false;
    bool checkt = false;
    if(s[0]=='A'){
        if(s[1]=='E'||s[1]=='B'){
            check = true;
        }
    }else if(s[0]=='E'){
        if(s[1]=='A'||s[1]=='D'){
            check = true;
        }
    }
    if(t[0]=='A'){
        if(t[1]=='E'||t[1]=='B'){
            checkt = true;
        }
    }else if(t[0]=='E'){
        if(t[1]=='A'||t[1]=='D'){
            checkt = true;
        }
    }
    if(s[0]+1==s[1]||s[0]-1==s[1]){
        check = true;  
    }
    if(t[0]+1==t[1]||t[0]-1==t[1]){
        checkt = true;  
    }

    if(checkt==check){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}