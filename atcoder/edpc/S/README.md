# EDPC: S

1. 下回ったかどうか
2. 割った余り

この２点は頻出。頭から1つずつ追加していくことを考える。

```
// dp[i文字目][割った余りがj][既にkを下回ったかどうか] :=　パターン数
```

まだ下回っていない場合はk[i]以下の数しか使えないが、下回った場合は任意の数を追加できる。

xを追加したとして、 `j * 10 % D` に遷移する。 `Dの倍数である` = `Dで割った余りが0` なので答えは `dp[n][0][true] + dp[n][0][false]` 。
