# ABC110 D

Mを素因数分解する。

ある素数PでMをX回割れるとき、Pをa1〜anのどこに割り振るかを考える。

一列に並ぶX個のオブジェクトをn個に区切るパターン数に相当するが、これは重複組合せなので `combination(n+x-1, n)` になる。

全ての素数に対してパターン数を求めて掛け合わせれば答えになる。