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
    int m;
    int d[100];
    cin >> m;
    int days = 0;
    rep(i,m){
        cin >> d[i];
        days += d[i];
    }

    days /= 2;
    int count = 0;
    rep(i,m){
        if(days<d[i]){
            cout << i+1 << " " << days+1;
            break;
        }else{
            days -= d[count];
            count++;
        }
    }
}