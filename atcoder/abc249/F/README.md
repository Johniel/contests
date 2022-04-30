# AtCoder Beginner Contest 249 F - Ignore Operations
```c++
  int k;
(中略)
      if (k < q.size()) {
```
だと`k`が負の場合に正しい比較が出来ない？
```c++
  int k;
(中略)
      if (k < (int)q.size()) {
```
ならACだった。`size()`は確かに`unsigned int`だけどそこは良い感じに解釈して欲しい。
