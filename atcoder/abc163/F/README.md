# ABC163F
ある色を1度以上通るパスはいくつ通るか分からないし重複を除くのも面倒そう。1度も通らない方を数えてみる。

根付き木を考えて、頂点v,uが同じ色(Cv=Cu)であり、そのパス上に他にCvを持つ頂点が存在しないものとする。

その色で木を分割したときの連結成分を思い浮かべると良いのかもしれない。連結成分に属する頂点間のパスはその色を使うことがない。

vからuに向かうパス上の直接の子をw、iを根とする部分木の大きさをSiとした場合、vで区切られたvより深い方の連結成分の頂点数は、Σ|Sw|-Σ|Su| になる。

縞模様が考えられるので実装でもスタックを使うなど少し工夫が必要。

あとは考えられるパスの総数から、ある色を1度も通らないパスの本数を引き算する。
