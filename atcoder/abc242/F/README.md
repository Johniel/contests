# AtCoder Beginner Contest 242 F - Black and White Rooks

詳細は覚えていないけれど本番で解けなかった。解説を見る。

含除原理での解説は難しいので動的計画法での計算方法を参考にする。こちらは理解できる。

黒が配置される行と列を選ぶ方法が`comb(h,bi)*comb(w,bj)`通り。

この中から各行と各列に１つ以上が配置されるパターン数は`fn(bi,bj,x)=comb(bi,bj,b)-sum{comb(bi,i)*comb(bj,j)*fn(i,j,x) if (i,j)!=(bi,bj)}`。この計算式、面白い。

AC。これを本番で解ける確率は1割未満だろうと思った。
