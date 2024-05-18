# lazy segtree v2 2024-05-18 16-19-58
[AtCoder Library Practice Contest L - Lazy Segment Tree](https://atcoder.jp/contests/practice2/tasks/practice2_l)で試す。
[再帰版](https://atcoder.jp/contests/practice2/submissions/51967030)が遅いのだろうと推察して実装しなおす。atcoder libraryが存在する状況でで自作は時代遅れだろうけれど。

## 参考
+ https://codeforces.com/blog/entry/18051
+ https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp

## メモ
lazy[k]がvalue[k]に適応済みであるかはこれまでのものと異なる。どちらに合わせるべきかは分からないけれどatcoder libraryに今は寄せる。

木を想像すると子か親への遷移を考えてしまうけれど`--`と`++`で左右の移動を行っていることに注意。
```
+---+---+
| A | B |
+-+-+-+-+
|C|D|E|F|
+-+-+-+-+
```

+ Dを見ていて`++`して`/2`するとB

``` cpp
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }
```
これは下位i桁に1があるかどうか、つまりそれより下で一度以上右の子への遷移が存在するかどうか。
```
+---------------+
|       _       |
+---------------+
|   _   |   _   |
+---+---+---+---+
| _ | A | B | _ |
+-+-+-+-+-+-+-+-+
|_|C|d|e|f|g|@|_|
+-+-+-+-+-+-+-+-+
```
IからMまでの範囲に注目している場合、範囲の左端が右の子である場合は右斜め上に遷移する`C`の次は`A`。
半壊区間なので`g`の代わりに`@`を見ている。

``` cpp
    for (int i = log; i >= 1; i--) {
      push(l >> i);
      push((r - 1) >> i);
    }
    for (int i = 1; i <= log; i++) {
      update(l >> i);
      update((r - 1) >> i);
    }
```
しかしこれだと駄目なの？右の子を範囲内の子孫に持つ頂点だけをupdateしなければいけないから無作為に子孫を対象にしていたらいけないのか。

いつも思っていたけれどpushというよりpropagateでないかな。


+ [533ms](https://atcoder.jp/contests/practice2/submissions/51967030)
+ [372ms](https://atcoder.jp/contests/practice2/submissions/53569849)
+ [.at()とassertを消して345ms](https://atcoder.jp/contests/practice2/submissions/53569932)
+ [inlineを追加して322ms](https://atcoder.jp/contests/practice2/submissions/53569980)

以前よりもましだけれどせめて300ms未満にはしたい。が、成功せず。一旦ここまで。

行数が前より長いのが気に入らない。再帰版を煮詰めた方が速かったりしない？実践では使わないのだけれど。
