# SRM616
本番はDiv1Easyだけ解いて115.51pt

## Div2

## WakingUpEasy
250

やるだけ

## ColorfulCoinsEasy
500

X % max(values) を全部試す。

1番目に大きい数値でmod, 2番目に大きい数値でmod, ... と処理するので、

実は X / max(values) はどんな数値でも問題ない。

## Div1

## WakingUp
250pt

二分探索する。

それぞれの周期が10以下なので、あるSで起床できるか確認する必要のある時間

はLCM(1, 2, ... 9, 10)くらい。

眠りが深くなる一方かどうかは、その周期の増減が0より大きいかどうかで判定
