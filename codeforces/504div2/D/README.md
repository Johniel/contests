# CF504Div2D
a[i] = a[j] のとき、 a[k] < a[i] (i < k < j) となるような要素が存在しなければ良い。

調べるにはRMQを使う。

１つ以上連続する 0 はその左右の大きい方の数字で埋める。

a に q が含まれていなければいけないことに注意する。