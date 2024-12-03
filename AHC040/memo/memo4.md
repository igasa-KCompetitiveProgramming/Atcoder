## 上下選択パターン中

### やばそうな点

決め打った正方形の形以上になった時にどうするかが問題児

- 一旦正方形以上になってないほうに詰めまくります

## 現状のコード

```
int main(){
    LL(n,t,sgm);
    v(w,n,0);v(h,n,0);
    vector<bool> isVertical(n, false);
    rep(n) cin >> w[i] >> h[i];
    ll areaSum = 0;
    rep(n){
        areaSum += w[i] * h[i];
        if(w[i] < h[i]){
            isVertical[i] = true;
            swap(w[i], h[i]);
        }
    }
    ll length = sqrt(areaSum);
    ll cnt = 0;
    vector<pll> u,l;
    vector<tuple<ll,ll,char,ll>> ans;
    ans.pb({0,0,'U',-1});
    u.pb({h[0],-1});l.pb({w[0],-1});
    ll avrU, avrL;
    ll nextU, nextL;
    nextU = 0; nextL = 0;
    avrU = w[0]; avrL = h[0];
    ll wide = w[0];ll height = h[0];
    bool flag = false;
    for(ll i = 1; i < n; i++){
        if(abs(avrL - w[i]) > abs(avrU - h[i])){
            avrU += w[i];
            height += h[i];
            avrU /= 2;
            u.pb({w[i],i});
            ans.pb({nextU,0,'U',i});
            nextU = i;
            if(length < height){
                flag = true;
            }
        }else{
            avrL += h[i];
            wide += w[i];
            avrL /= 2;
            l.pb({h[i],i});
            ans.pb({nextL,0,'L',i});
            nextL = i;
            if(length < wide){
                flag = true;
            }
        }
    }
}
```