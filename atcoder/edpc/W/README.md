# Educational DP Contest: W Intervals

[問題文](https://atcoder.jp/contests/dp/tasks/dp_w)

```
dp[i] = 最後に１を立てたのが位置iの場合の最大値
```

区間の終端順にテーブルを更新する。

```
dp[i + 1] = max({dp[0], ... dp[i]});
// ajはiを終端とする区間jのスコアで、kは区間jに含まれる。
dp[k] += aj;
```

これらは、
+ 区間に対するmax
+ 区間に対するadd
+ １カ所の更新

があれば実現できるので区間に対する操作をO(log N)で可能なデータ構造（遅延セグメント木等)を使って解ける。
