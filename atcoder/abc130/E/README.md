# ABC130 E

```
f(i,j) := i以降のSとj以降のTで作れる共通部分列の個数

f(i,j) := fn(i+1,j) + fn(i,j+1) - fn(i+1,j+1) + fn(i+1,j+1) + 1 // si != tj
f(i,j) := fn(i+1,j) + fn(i,j+1) - fn(i+1,j+1) // si == tj
```

`f(i+1,j+1)` を `f(i+1,j)` と `f(i,j+1)` で２回カウントしてしまうので引き算する。

`si == tj` の場合はsi,tjより後ろを使うパターン数f(i+1,j+1)と使わないパターン数1を足す。