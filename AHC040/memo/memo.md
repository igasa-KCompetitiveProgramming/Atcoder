# したいこと

- でかい長方形を周の長さの短い正方形にしたいよーみたいなお話
- なんかt回操作を出力しないと行けなさそう?
  - 焼けって言ってそう()もしくは全探索気味なことをしろってこと？
  - ~~まぁおんなじ回答をn/2回出力でもACはしそう~~
  - 標準偏差があるので同じ回答を出したほうが良い可能性がかなり高そうですね

# 解法メモ1(先にhとwの和を求めておく)

求めたらどうなりますか？
- 知りません、人類が
- hとwを回転可能で総和の差を最小化できるならちゅよい

# 解法メモ2(1の派生、先に面積を求めておく)

面積を求めることでどれくらいの大きさの正方形にすれば良いかの検討がつくのでは？
- ある程度大きめになることを想定しておいてなんか頑張る()
- 回転可能でなくてもやりやすそう
- できる限り高さの凸凹を小さくしたいなぁというお話

# 実際のコードに落とそうの回

## フェーズわけしませんか…?

- 前計算
  - あらかじめどれくらいの正方形になるかの検討がついていればわかりやすそう
- 空白は小さくしたくないですか..?
  - 高さの近い長方形で1段落を作るor2個の長方形を組み合わせる

### 面積計算→凸凹最小化

#### 面積計算ゾーン
- 面積計算は流石にez
  - 

#### 凸凹最小化ゾーン

- とりあえず脳死します()

## 脳死ゾーン

上のことを考えてたら死ぬので、とりあえずちょっと楽そうなのを考えようの会

Nが高々100なのでわりといろんなのが通る

- Σ[n][i=0](n)のルート
  - 毎回LとUについて今まで置いたものについて考慮できるので割と良さげ

- 正方形に近似させるルート
  - 列に並べる近似と行に並べる近似がありそう
  - もしくは同時進行...？

