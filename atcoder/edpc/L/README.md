# EDPC: L

区間を考える。

```
// dp[左端のindex][右端のindex] := X-Yの最適値

// 太郎のターン
dp[i][j] = max(dp[i + 1][j] + ai, dp[i][j - 1] + aj)

// 次郎のターン
dp[i][j] = min(dp[i + 1][j] - ai, dp[i][j - 1] - aj)
```
