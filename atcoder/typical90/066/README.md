# 競プロ典型 90 問 066 - Various Arrays（★5）
`fn(どこまで決めた,最大値):=期待値` みたいな感じだろうか？いや、一様にランダムということは数値は重複するのか。

N<=100なので割と色々できそう。

サイコロの出目3つの並びで転倒数の期待値を考えると、それらしい計算をして足せば（線形性）答えになる気がする。
つまり、i番目に出現した整数nとj番目(i<j)に出現する数との期待値を別々に計算して良い（はず）。

`fn(最初に整数iが選ばれた、転倒数k個):=確率` でどうだろう。O(N^4)?遅いかな。

以前は8次元DPくらい平気で実装していた気がするけれど最近は4次元で四苦八苦する。老いかな。