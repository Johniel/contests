# 516div2 D
左右のどちらかを優先して最小化するような戦略を取る。
```
+---x
|
+-------->y
```

例えば上記のように左へ進んで迂回する必要があるとして、結局その分を右に進まなければいけない。

なので、迂回の部分は左右で移動回数が同じになるため、どちらかの方向だけ考えて最小化させれば良い。

