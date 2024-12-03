## 一旦倍率ゲーします

- ksです！普通に頑張ってください！
- max値求めてleft流しの方が良いのでは？ということで頑張ります

## 作ったけどあんま良くなってないです

```
int main(){
    LL(n,t,sgm);
    v(w,n,0);v(h,n,0);
    rep(n) cin >> w[i] >> h[i];
    ll areaSum = 0;
    rep(n){
        areaSum += w[i] * h[i];
    }
    vector<long double> coef((t+2)/3,0);
    rep(i,(t+2)/3){
        long double j = i;
        ll sla = (t+2)/3;
        coef[i] = 0.9 + 0.2 * j/sla;
    }
    ll length = sqrt(areaSum);
    ll tmp = 0;
    ll cnt = 0;
    ll cnt2 = 0;
    bool flag = true;
    rep(j,t){
        if(j%3 == 0){
            tmp = length * coef[cnt2];
            cnt2++;
            //cout << tmp << endl;
        }
        cout << n << endl;
        bool flag = true;
        cnt = 0;
        rep(i,n){
            cout << i << spa;
            cnt += max(w[i], h[i]);
            if(w[i] < h[i]) cout << 1 << spa;
            else cout << 0 << spa;
            cout << "U" << spa;
            if(flag){
                cout << "-1" << endl;
                flag = false;
            }else{
                cout << i-1 << endl;
            }
            if(cnt > tmp){
                flag = true;
                cnt = 0;
            }
        }
        cout << endl;
    }
}
```

## 深刻なバグのせいで点数が標準偏差ゲーで多少増加が見受けられる

```
int main(){
    LL(n,t,sgm);
    v(w,n,0);v(h,n,0);
    rep(n) cin >> w[i] >> h[i];
    ll areaSum = 0;
    rep(n){
        areaSum += w[i] * h[i];
    }
    ll length = sqrt(areaSum);
    ll cnt = 0;
    bool flag = true;
    rep(j,t){
        cout << n << endl;
        bool flag = true;
        cnt = 0;
        rep(i,n){
            cout << i << spa;
            cnt += max(w[i], h[i]);
            if(w[i] < h[i]) cout << 1 << spa;
            else cout << 0 << spa;
            cout << "U" << spa;
            if(flag){
                cout << "-1" << endl;
                flag = false;
            }else{
                cout << i-1 << endl;
            }
            if(cnt > length){
                flag = true;
                cnt = 0;
            }
        }
        cout << endl;
    }
}
```

## 現状のコード

```
int main(){
    LL(n,t,sgm);
    v(w,n,0);v(h,n,0);
    rep(n) cin >> w[i] >> h[i];
    ll areaSum = 0;
    rep(n){
        areaSum += w[i] * h[i];
    }
    ll length = sqrt(areaSum);
    ll cnt = 0;
    vector<pll> u,l;
    vector<tuple<ll,ll,char,ll>> ans;
    ans.pb({0,0,'U',-1});
    u.pb({h[0],-1});l.pb({w[0],-1});
    ll avrU, avrL;
    ll nextU, nextL;
    nextU = -1; nextL = -1;
    avrU = w[0]; avrL = h[0];
    ll wide = w[0];ll height = h[0];
    bool flag = false;
    for(ll i = 1; i < n; i++){
        if(abs(avrL - w[i]) > abs(avrU - h[i])){
            avrU += w[i];
            height += h[i];
            avrU /= 2;
            u.pb({w[i],i});
            ans.pb({i,0,'U',nextU});
            if(length < height){
                while(true){
                    if(wide > length) break;
                    if(n == i) break;
                    i++;
                    avrL += h[i];
                    wide += w[i];
                    avrL /= 2;
                    l.pb({h[i],i});
                    ans.pb({i,0,'L',nextL});
                }
                flag = true;
            }
        }else{
            avrL += h[i];
            wide += w[i];
            avrL /= 2;
            l.pb({h[i],i});
            ans.pb({i,0,'L',nextL});
            if(length < wide){
                while(true){
                    if(height > length) break;
                    if(n == i) break;
                    i++;
                    avrU += w[i];
                    height += h[i];
                    avrU /= 2;
                    u.pb({w[i],i});
                    ans.pb({i,0,'U',nextU});
                }
                flag = true;
            }
        }
        if(flag){
            ll res = 0;
            while(!l.empty()){
                auto [a,b] = l.back();
                l.pop_back();
                res = max(res,a);
                if(res == a){
                    nextU = b;
                }
            }
            res = 0;
            while(!u.empty()){
                auto [a,b] = u.back();
                u.pop_back();
                res = max(res,a);
                if(res == a){
                    nextL = b;
                }
            }
        }
    }
    rep(t){
        cout << n << endl;
        rep(ans.size()){
            auto [a,b,c,d] = ans[i];
            cout << a << " " << b << " " << c << " " << d << endl;
        }
    }
}
```