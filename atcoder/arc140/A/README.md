# AtCoder Regular Contest 140 A - Right String
unrated参加。本番メモ。

+ f(T)が任意の回数の操作ということは始点は|T|パターンありえる。
+ Sの文字をk箇所まで選んで変更出来る。f(S)の最小値は？
+ Sを、ある文字列の繰り返しの形に変えられれば良い。その文字列の長さがf(S)に相当する。
+ 長さを全て試したらO(N log N)が出てこないかな。全体でO(N^2 log N)。
+ [投げた](https://atcoder.jp/contests/arc140/submissions/31716534)。WA。AC3+19,WA15。
+ 手で小さいケースを試した。繰り返しの長さが|S|の約数であるという確認を追加。
+ [AC](https://atcoder.jp/contests/arc140/submissions/31716949)。
