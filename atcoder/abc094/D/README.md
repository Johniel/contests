# ABC094 D
`comb(n, k)` のkを固定した場合、nは大きい数字を選んだ方が計算結果を大きくできる。

つまりkをどう選ぼうとnはaの中の最大値を選ぶべきとなる。

また、`comb(n, k) == comb(n, n - k)` なので、n/2を超えない大きな値を選べば良い。

