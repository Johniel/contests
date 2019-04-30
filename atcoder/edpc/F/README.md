# EDPC: F

普通のLCS。文字列をa,bとすると。

```
// dp[aをi番目まで見た][bをj番目まで見た] =　最長の共通部分列の長さ
// ai = bjなら
dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1])
// ai != bjなら
dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
```
