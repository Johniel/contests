# [Codeforces Round #709 (Div. 1, based on Technocup 2021 Final Round) B. Playlist](https://codeforces.com/contest/1483/problem/B)
## "2021-04-29 17-30-33"
整数を持つN<=1e5個の要素からなる循環リストが与えられる。0から順に、直前の要素とのGCDが1となる場合にその要素を取り除くという操作を繰り返す。
削除される要素のインデックスを時系列で出力せよ。

Div2でD問題だし難しくないはずなんだけど本番では解けなかった。

e.g.)
> [_5_, 9, 2, 10, 15] → [5, _9_, 2, 10, 15] → [5, 2, 10, 15] (because gcd(5,9)=1) → [5, _2_, 10, 15] → [5, 2, _10_, 15] → [5, 2, 10, 15] → [5, 2, 10, _15_] → [_5_, 2, 10, 15] → [5, 10, 15] (because gcd(5,2)=1) → [5, _10_, 15] → [5, 10, _15_]

順番にループを回していてはO(N^2)なのでダメそう。次に削除される要素をlogNくらいで求められれば良い。素因数分解なりを事前に行って良い感じに管理していくんだろうか。

> It is also possible to solve this problem with double-linked lists or DSU with O(nlogC) complexity.

なるほど？前後のインデックスさえ覚えておけば良いのか。

> Oops! Probably Codeforces can't be reached right now or your Internet connection is broken.

コンテスト開催中でないのにOops!するの本当に止めて欲しい。

> wrong answer 23rd numbers differ - expected: '25', found: '22'

ふぁー。1000ケースあるし不可視。

20分後。

インデックスの更新タイミングを間違えていた。AC。これは本番で通すべきだった。
