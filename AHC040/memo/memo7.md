# 私が最強だと思っていたものは最弱だったのかもしれない

maxだといいスコアってことになってるのでmaxに合わせたやつがksみたいなことになってる、ks
要約plz
- 初期解最強gg!!!!!

# 正攻法解法

- 次なる最強解を目指します、具体的には、焼きます

## 詳細説明

- **焼く**
  - 正方形liker縛りを入れます
    - 初期解に導入した通り、面積から求めてください(長さから求めようとすると大変なことになります(1敗))
  - $N<100$であることを念頭においてください。
    - $N^3$まではezです、$N^4$もギリACです
      - んなもん関係ありません、時間で区切ります
  - どうやって焼くおつもりですか？
    - 完璧を求めようと思ったら多分死にます(？)
    - 入るな〜ちょっと凸凹するけどでも入れるような仕組みにしておかないと実装がクソ大変な上に結局初期解最強じゃね？となります
    - 入るな〜の基準についてのお話
      - 基本的には横長にして入れたい、しかし、ある一定基準を満たすのであれば、左端に寄せるのでよさそう？
        - 横長至高の理由:
  - 再び燃え盛り出す前計算の可能性
    - (事前に5つorもっと多くorSqrt(n)!?)にグルーピングができるのであればちょー強い
      - ま、けの概念
        - グルーピングがうまくいかないパターン
          - 段階が別れすぎていて、平均してもうまくいかない
          - グルーピングができても順番的に不可能なグルーピングになってしまう可能性
            - これは、最初のsqrt(n)個左端寄せを確定させるなどの対処で対応は一応可能
      - 勝ちの概念
        - グルーピングがうまくいくパターン
          - 順番的に可能
          - それぞれの行を見た時、平坦な高さに収まっている(yの増加量が少なめ)
            - avrHを最初の長方形基準でやるleftでやったら高さ制限のせいで入らないみたいなksパターンが最も恐怖
          - それぞれの列を見た時、どの列も同じくらいの高さになっている
            - avrHをlengthに近づける？
            - 順番の制約が多少緩い
              - 縦の積み上げなので問題は左のやつがwideがでかくてバグらせちゃった！みたいなパターンが多発しそうなこと
        - グルーピングがとてつもない勢いでうまくいくと、avrH&&sumWかsumH&&avrWのどちらかを満たす
  - 評価関数はいかがしますか
    - LorUを迫るだけ？
      - no、できることならピタっとハマるやつが欲しい
      - ↑補足、x,y軸をある長方形に合わせられるのでそれができる
    - 正直、スコア計算欲しい？
      - いらん、帰ってくれ
      - どっちかっていうと絶対に入れられなくなった部分の面積を求められようものならそれは最強の評価関数になりうる
  - え？貪欲ビームじゃだめなんすかこれ(焼くとは??????)
    - 貪欲ビームだとしたらあなたどうやって実装するおつもりですか？
      - とりあえず愚直に真似して書いたほうが早そうですね
    - 多分上にグチャラティグチャラティしてるものよりもこっちのほうが単純で強そうだなぁというイメージがある
    - では、恒例の評価関数はいかがされるんですか？
      - length寄せは絶対、守らなきゃ極刑
        - 最適解はL字を綺麗に作り上げること
        - と、いいたいのですが、多分↓みたいな形が一番こねこねしやすそう
          - 適当に最初の貪欲っぽく埋める
          - 途中でやめて、先にUで入れてもいい
            - 但し、下のWを超えるような長方形を入れる時は要注意
        - ↑をするといいところ
          - 今のコードのままでwideをlength寄せしながらheightを伸ばし続ける形にできる

## そんな最強な初期解

- こいつ割と致命的なバグ出てんのに強いのまじでなんなの

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