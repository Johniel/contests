# AtCoder Beginner Contest 206（Sponsored by Panasonic）E - Divide Both

GCDがkの倍数となる整数の組(x,y)の個数は `f(k):=((r/k)-(l-1)/k)^2`
GCDがちょうどkの倍数となる整数の組(x,y)の個数は `g(k):=f(k)-g(2k)-g(2k)-...`
この関数gは*大きい方から*計算すると良い。約数系包除原理と言うらしい？

このままだと `xがyの倍数ではない` という条件がまだ。
xとyの小さい方をxとしてL<=xの場合に、xの倍数は範囲内に `(r/x)-(l-1)/x` 個ある。
入れ替えを考えるとその2倍、x=yを引き過ぎるので+1。

あとはg(l)からg(r)までの総和が答え。

解説にある平方数で割れるなら-,割れないなら+という計算方法は面白いと思った。
