# AtCoder Beginner Contest 277 G
`積の和典型` ってなに？初めて聞いたわ。

[ei1333の日記 2021-07-30 積の和典型](https://ei1333.hateblo.jp/entry/2021/07/30/144201)。

なるほど。M個の区別できないボールをNグループに分けたうえでグループから１つだけを黒く塗る方法が `M+N-1CN+N-1`。

グループ分けだけなら `M+N-1CN-1` だが、区切りだけでなく黒も一緒くたにして問題ない。なぜならN+N-1個を選んだら黒、区切り、黒、区切り、...となるから。

上記の記事内でABCから類似の問題が紹介されているがどれも解けていない。当然か。ひとまず２つだけ選んできた。
+ https://atcoder.jp/contests/arc110/tasks/arc110_d
+ https://atcoder.jp/contests/abc231/tasks/abc231_g
