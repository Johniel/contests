# 競プロ典型 90 問 073 - We Need Both a and b（★5）
赤だけの連結成分と青だけの連結成分とに分割して、それぞれのサイズを元に計算できないかな。

1. 条件を満たす方でなく、満たさない方を考える。
2. 隣接する赤の頂点だけを部分木（連結成分）として取り出す。
3. その部分木のサイズ（頂点数）がmだとして、2^(m-1)パターンの分割の仕方がある。
4. 部分木毎にパターンを計算し、2^(n-1)からその総積を引き算する。

でどう？

いや、部分木1にだけ注目したとして、他は任意になる。それだと別の箇所で条件を満たさないものが現れたら重複して数えることにならない？困った。

解説をチラ見する。色が2色しかないから状態に持てるのかなるほど。

`fn(どの頂点,aを連結に含むか,bを連結に含むか):=パターン数` とか？でも状態遷移が少し難しいような気がする。

まず、知りたいのは `fn(root,true,true)` 。仮にrootがa、子が2つ(c1,c2とする)あるとして、

## c1にだけ辺を残す場合
`(fn(c1,false,true)+fn(c1,true,true))*fn(c2,true,true)`

## c2にだけ辺を残す場合
`fn(c1,true,true)*(fn(c2,false,true)+fn(c2,true,true))`

## 両方に辺を残す場合
`(fn(c1,false,true)+fn(c1,true,true))*(fn(c2,false,true)+fn(c2,true,true))`

## まとめると
`fn(root,true,true):=(fn(c1,false,true)+fn(c1,true,true))*fn(c2,true,true)+fn(c1,true,true)*(fn(c2,false,true)+fn(c2,true,true))+(fn(c1,false,true)+fn(c1,true,true))*(fn(c2,false,true)+fn(c2,true,true))`

これ本当？かなり大きくなりそうな式だけれど。bの場合はfalseになっているパラメータを逆にする。

分からないので再び解説を見る。`Π(dp[bi][0]+dp[bi][2])` が分からない、辺の無い子の方で両方を含まないといけない理由が。

一旦諦める。
