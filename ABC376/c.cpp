#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19
int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n-1);
    multiset<int> s;
    int maxSize = 0;
    rep(i,n){
        cin >> a[i];
        maxSize = max(maxSize,a[i]);
    }
    sort(a.begin(),a.end());
    rep(i,n-1){
        cin >> b[i];
        s.insert(b[i]);
    }
    int left = -1;
    int right = maxSize+1; // rightは各自設定
    while(right - left > 1){ //rightは配列[mid]より小さい最大値に、leftは配列[mid]より大きい最小値になる
        int mid = left + (right - left) / 2;
        int i = 0;
        bool flag = true;
        s.insert(mid);
        for(auto x : s){
            if(x < a[i]){
                flag = false;
                break;
            }else{
                i++;
            }
        }
        s.erase(s.find(mid));
        if(flag){
            right = mid;
        }else{
            left = mid;
        }
        if(right < left) break;
    }
    if(right == maxSize+1) right = -1;
    cout << right << endl;
}