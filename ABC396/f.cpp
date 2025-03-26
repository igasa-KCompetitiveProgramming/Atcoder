#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rrep1(a)          for(ll i = (ll)(a-1); i >= (ll)0 ; i--)
#define rrep2(i, a)       for(ll i = (ll)(a-1); i >= (ll)0; i--)
#define rrep3(i, a, b)    for(ll i = (ll)(a-1); i >=(b); i--)
#define rrep4(i, a, b, c) for(ll i = (ll)(a-1); i >=(b); i -= (c))
#define overload4(a, b, c, d, e, ...) e
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)

#define rep1(a)          for(ll i = 0; i < (ll)(a); i++)
#define rep2(i, a)       for(ll i = 0; i < (ll)(a); i++)
#define rep3(i, a, b)    for(ll i = (a); i < (ll)(b); i++)
#define rep4(i, a, b, c) for(ll i = (a); i < (ll)(b); i += (c))
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define fi first
#define se second
#define pb push_back
#define spa " "

//！？！？
#define O print

inline void scan(){}
template<class Head,class... Tail>
inline void scan(Head&head,Tail&... tail){std::cin>>head;scan(tail...);}
#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)

#pragma GCC diagnostic ignored "-Wunused-value"
void print(){cout << '\n';}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){cout << a;(std::cout << ... << (cout << ' ', b));cout << '\n';}
#pragma GCC diagnostic warning "-Wunused-value"

int inf = 2147483647; // おおよそ2*10^9
ll INF = 9223372036854775807; //おおよそ9*10^18
//ull UINF == おおよそ1.8*10^19

long long ans=0;
int a[500005],temp[500005];
void s(int l,int r) {
	if(l==r)return;
	int mid=(l+r)/2;
	s(l,mid);
	s(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r) {
		if(a[i]<=a[j]) {
			temp[k]=a[i];
			k++;
			i++;
		} else {
			temp[k]=a[j];
			ans+=mid-i+1; 
			k++;
			j++;
		}
	}
	while(i<=mid) {
		temp[k++]=a[i++];
	}
	while(j<=r) {
		temp[k++]=a[j++];
	}
	for(int i=l; i<=r; i++)a[i]=temp[i];
}
int main() {
	int n,m;
	cin>>n >> m;
    vector<vector<int>> se(m);
	for(int i=0; i<n; i++) cin>>a[i];
    for(int i = 0; i < n; i++){
        if(a[i] == 0) continue;
        se[m-a[i]].push_back(i);
    }
	s(0,n-1);
	rep(se.size()){
        rep(j, se[i].size()){
            ans += se[i][j] - (n - se[i][j] - 1);
        }
        cout << ans << endl;
    }
}