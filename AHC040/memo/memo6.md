## いい加減にちょっとは考えるコードを作りましょう

限られた時間の中で書きたいコードの内容を多少はまとめておきましょう

# あなたが書きたいコードは？

- 正方形の形決めうちパラダイス
  - ↑に対して今思ったもの
    - それって意外とできるんじゃないでしょうか？

# 正攻法解法

- **焼く**
  - 正方形liker縛りを入れます

# ダメそうな解法まとめ

- 分割
- 隙間を減らす工夫をしたいが、ダイレクトに座標計算をしだすとahc039みたく幾何で私が死ぬ
- 凸凹を減らす工夫をしましょうの回

# 今より良くなりそうだなぁなノリの3秒クオリティ解法

- ~~分割で頑張りたかったお話~~
  - 1. あまりにも細長いやつらを左に寄せる
  - 左とは？とか細長いの基準とは？で無事廃案
- ~~分割自体は使えるのでは？~~
  - 要は細長or正方形を考えればいい
    - 1で細長、2で正方形なら？
      - 死にそう
  - そんなことなさそう、廃案
- avrを取り続けて、回転も可で最小の差を探し出す
  - avrじゃなくてmaxの方が良いのでは？
    - +だったときのプライオリティに重さを乗せるのがしんどそう
    - だが、どのみちこれがかなり良さそうな雰囲気を醸し出している
- 焼くwith正方形liker縛り
  - モンテカルロさん！？
  - いい加減焼くことを覚えろksする時がきた

## 現状の最強コード:max値にあわせていい感じにするコードを作りました

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
    ll maxH = 0;
    ll maxHitr;
    ll Hitr = -1;
    rep(j,t){
        cout << n << endl;
        bool flag = true;
        cnt = 0;
        rep(i,n){
            cout << i << spa;
            cnt += max(w[i], h[i]);
            maxH = max(maxH,min(w[i],h[i]));
            if(maxH == min(w[i],h[i])) maxHitr = i;
            if(w[i] < h[i]) cout << 1 << spa;
            else cout << 0 << spa;
            cout << "L" << spa;
            cout << Hitr << endl;
            if(cnt > length){
                flag = true;
                cnt = 0;
                Hitr = maxHitr;
                maxH = 0;
            }
        }
        cnt = 0;
        Hitr = -1;
        maxH = 0;
        cout << endl;
    }
}
```