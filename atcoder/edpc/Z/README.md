# EDPC: Z

[ConvexHullTrick](https://codeforces.com/blog/entry/63823)。蟻本にはdequeの活用方法のあたりに載っている。これはDPなんだろうか。

足場iと足場jで移動する場合のコストは `f(hi)=min{(hi-hj)^2+C+f(hi)}` になる。

変形した `f(hj)=min{hi^2-2*hi*hj-hj^2+C+f(hi)}` という式を見ると、`-2*hi` を傾きにしようにも `hi^2` と `hj^2` が出てくるあたりどう扱って良いのか分からなかった。

が、管理する直線を `f(hj)=-2*hi*hj+hi^2+C+f(hi)` にしてしまえば良い。 `hj` は注目しているタイミングでは定数なので後から加算する。

柔らか頭でないと実装で戸惑う気がした。
