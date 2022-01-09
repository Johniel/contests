# AtCoder Beginner Contest 234 G - Divide a Sequence
## 本番中
max(あるいはmin)として選ばれる回数さえ分かれば計算できそうだなあ。

## その後
問題文を読み間違えていた駄目じゃん。ちゃんとサンプルを読もう。

```c++
    dp[0] = 1;
    for (int i = 0; i < a.size(); ++i) {
      for (int j = i+1; j <= a.size(); ++j) {
        lli mx = rmq_mx.query(i, j);
        lli mn = rmq_mn.query(i, j);
        (dp[j] += (mx - mn) * dp[i] % mod) %= mod;
      }
    }
    cout << dp[n] << endl;
```
計算量を無視した上で手癖で配るDPを実装するとしたらこう。

解説の感じだと貰うDPの方が良いのだろうか。書き換えを考えてみる。

```c++
    dp[0] = 1;
    for (int i = 0; i <= a.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        lli mx = rmq_mx.query(j, i);
        lli mn = rmq_mn.query(j, i);
        (dp[i] += (mx - mn) * dp[j] % mod) %= mod;
      }
    }
    cout << dp[n] << endl;
```

貰ってる感じは出ているけれど大差ない。これをminとmaxに分ける？

```c++
    dp[0] = 1;
    for (int i = 0; i <= a.size(); ++i) {
      lli mx = 0;
      lli mn = 0;
      for (int j = 0; j < i; ++j) {
        mx += rmq_mx.query(j, i) * dp[j] % mod;
        mn += rmq_mn.query(j, i) * dp[j] % mod;
        mx %= mod;
        mn %= mod;
      }
      (dp[i] += (mx - mn + mod) % mod) %= mod;
    }
    cout << dp[n] << endl;
```

はい、分けた。ループも分ける？

```c++
    dp[0] = 1;
    for (int i = 0; i <= a.size(); ++i) {
      lli mx = 0;
      for (int j = 0; j < i; ++j) {
        mx += rmq_mx.query(j, i) * dp[j] % mod;
        mx %= mod;
      }
      lli mn = 0;
      for (int j = 0; j < i; ++j) {
        mn += rmq_mn.query(j, i) * dp[j] % mod;
        mn %= mod;
      }
      (dp[i] += (mx - mn + mod) % mod) %= mod;
    }
    cout << dp[n] << endl;
```

こう。畳み込みみたい。

分かった。
rmq_mn.query(j, i)の値と、値が一致する範囲のdp[j]の総和を管理する。記憶の中のスライドminが蘇った。

```c++
    dp[0] = 1;
    stack<pair<lli, lli>> smx, smn;
    lli mx = 0, mn = 0;
    for (int i = 0; i <= a.size(); ++i) {
      if (i) {
        {
          pair<lli, lli> p = {a[i - 1], dp[i - 1]};
          while (smx.size() && smx.top().first < p.first) {
            pair<lli, lli> q = smx.top();
            smx.pop();
            mx = (mx - q.first * q.second % mod + mod) % mod;
            (p.second += q.second) %= mod;
          }
          (mx += p.first * p.second) %= mod;
          smx.push(p);
        }
        {
          pair<lli, lli> p = {a[i - 1], dp[i - 1]};
          while (smn.size() && smn.top().first > p.first) {
            pair<lli, lli> q = smn.top();
            smn.pop();
            mn = (mn - q.first * q.second % mod + mod) % mod;
            (p.second += q.second) %= mod;
          }
          (mn += p.first * p.second) %= mod;
          smn.push(p);
        }
      }
      (dp[i] += (mx - mn + mod) % mod) %= mod;
    }
    cout << dp[n] << endl;
```

AC。
