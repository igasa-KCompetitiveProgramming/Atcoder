#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 
int main(){
    int M,D,y,m,d;
    cin >> M >> D >> y >> m >> d;
    if(d==D&&m==M){
        d=1;
        m=1;
        y++;
    }else if(d==D){
        d=1;
        m++;
    }else{
        d++;
    }
    cout << y << " " << m << " " << d;
}