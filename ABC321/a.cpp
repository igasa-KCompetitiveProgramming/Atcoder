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
    int num;
    vector<int> n(6);
    bool check = true;
    bool ans = true;
    cin >> num;
    n[4] = num/10000;
    n[3] = num/1000 - n[4]*10;
    n[2] = num/100 - n[4]*100 - n[3]*10;
    n[1] = num/10 - n[4]*1000 - n[3]*100 - n[2]*10;
    n[0] = num%10;
    for(int i=5;i>=0;i--){
        if(check){
            if(n[i]!=0){
                check = false;
            }
        }else if(i!=5&&n[i+1]<=n[i]){
            ans = false;
        }
    }

    YesNo(ans);
}