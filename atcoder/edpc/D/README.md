# EDPC: D

普通のナップザック問題。wを重さ、vを価値とすると。

```
// dp[i番目までを使って][重さがj] := 価値の総和の最大。
dp[i][j] := min(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i])
```