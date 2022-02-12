# Codeforces Round #770 (Div. 2) [D. Finding Zero](https://codeforces.com/contest/1634/problem/D)
本番で通せなかった。
```
Hint 1
The problem can be reworded as follows: find n−2 indices that definitely can't contain a zero.
```

なるほど、本番では0を探しにいってしまった。逆ね。

```
Hint 3
Solve the problem for even n using the solution for n=4.
```

偶数・・・？

a, b, c, dのn=４だとして、x'をxを含まない３値にたいする結果だとする。

+ a'=max(b, c, d)-min(b, c, d)
+ b'=max(a, c, d)-min(a, c, d)
+ c'=max(a, b, d)-min(a, b, d)
+ d'=max(a, b, c)-min(a, b, c)

a=0, b<=c<=dのとき、

+ a'=d-b
+ b'=d
+ c'=d
+ d'=c

このとき、c<=d,d-b<dになる。
これで最も大きい２（あるいは３）箇所を除外することができる。

---

大きい箇所に注目するところまでは分かったのだけれど何がいけなかったのか。

でも、候補を２つずつ順番に消していくという発想はなかった。何故だ。

奇数の場合は１回余計に問い合わせるだけ。

AC。
