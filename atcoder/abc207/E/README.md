# AtCoder Beginner Contest 207 E - Mod i
```
長さNの数列Aが与えられます。Aをいくつかの連続した空でない部分列B1,B2,…,Bkに切り分ける方法であって、以下の条件を満たすものの個数を求めてください。
・全てのi(1≤i≤k) について、Biに含まれる要素の総和がiで割り切れる。
答えは非常に大きくなることがあるので、(10^9+7) で割ったあまりを出力してください。
```
```
・N≤3000
・1≤Ai≤10^15
・入力は全て整数
```

`fn(どこまで見た,Bの長さi,和modi):=パターン数`だと空間計算量がO(N^3)でアウト。
`fn(どこまで見た,Bの長さi):=パターン数`にして、次に和がiで割り切れるインデックスを事前計算する方向で考えたい。
累積和を思い出すとBxからByまでの和がiで割り切れるなら`(0からBxまでの和)-(0からByまでの和)=0`になる。
和modiが直前に出現した位置を覚えておいてO(1)で遷移できれば良いはず。`N≤3000`なので3000*3000くらい？
絶対に半開区間か何かで間違うやつ。

全然合わない。何。解説を見て配るDPを貰うDPに変えたら通った。何故。

```
dp[i][j] = (dp[g[j][i]][j] + dp[g[j][i]][j - 1]) % mod;
```

```
(dp[g[j][i]][j + 1] += dp[i][j]) %= mod;
(dp[g[j][i]][j] += dp[i][j]) %= mod;
```

しかしこれTLEギリギリだなあ。1.7msec。

```
const int k = g[j][i];
dp[k][j] += dp[i][j];
if (j) dp[k][j] += dp[i][j - 1];
```
これなら合いそう。前処理で作っているテーブルと添字の意味が一致していないのかな。分からなかった。
しかしTLEする。困った。前処理でmapを使っている部分を静的配列に変えて・・・。AC。