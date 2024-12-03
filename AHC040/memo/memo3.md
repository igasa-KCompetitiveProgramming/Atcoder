# ２の縦verも実装しました

## 結果

変わりません！ksです!!!

## 次なる実装方針

- Σnパターンを試します
- 正方形パターンも合わせろ！焼け！絶対！！！！！

## どうやってΣnパターンを錬成するんですか？

- LとUでくっつける時のための長さを持つ
- 以下の条件で削除
  - 別のものをくっつけた:単に入れ替えでいいのでは？
  - lengthを超えた:入れ替え時にどうするか考える
  - 横に入れるなら一番出っ張ってるやつを参照する:どうするの？
    - 入れる方向を上or左に固定すれば意外にも上手く行くのでは
      - 出っ張ったタイミングで更新

- まぁ今の状況よりかはある程度良くなる(?)はずなので適当にやってもいいのではないでしょうか

## Σnパターンを完全に作るのはちょっとしんどいので右に入れるか下に入れるかの2択を迫ればいいのではないでしょうか

- 

~~あんま増えなかった~~変わんなかった横verもいれたやーつ
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
    bool flag = true;
    ll t2 = t/2;
    rep(j,t2){
        cout << n << endl;
        rep(i,n){
            cout << i << spa;
            cnt += w[i];
            if(isVertical[i]) cout << 1 << spa;
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
    }
    flag = true;
    rep(t - t2){
        cout << n << endl;
        rep(j,n){
            cout << j << spa;
            cnt += w[j];
            if(!isVertical[j]) cout << 1 << spa;
            else cout << 0 << spa;
            cout << "L" << spa;
            if(flag){
                cout << "-1" << endl;
                flag = false;
            }else{
                cout << j-1 << endl;
            }
            if(cnt > length){
                flag = true;
                cnt = 0;
            }
        }
    }
}
```