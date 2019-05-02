# EDPC: U

状態はビットで持つと良い。ウサギのグループ分け毎に得られる得点は列挙しておく。

愚直な実装をすると `O(2^2N)` になるが、最も下位の1を取り除くように計算すると `O(3^N)` になる。
※ bit = (bit - 1) & bit

詳しくは蟻本を読む。


```
// dp[既に割り当てたウサギの集合] := パターン数
// ウサギのグループzで得られる得点をscore[z]とすると、
dp[x | y] = min(dp[x] + score[y])
```