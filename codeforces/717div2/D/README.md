# [Codeforces Round #717 (Div. 2) D. Cut](https://codeforces.com/contest/1516/problem/D)
## "2021-04-29 18-40-04"
長さn<=1e5の数列と、q<=1e5個のクエリが与えられる。
クエリは数列の範囲をしていするもので、LCMが積と一致するように範囲を部分列に分割すると最小でいくつの部分列を構築できるか答えよ。

本番ではこの１つ前の問題に時間を使ってしまって解けなかった覚えがある。尺取り法っぽさを感じる。
でもクエリ毎に尺取りしていても間に合わないから事前に何か構築するんだろうか。

同じ素因数を持たないようにすれば良いのかな。GCDが1であり続けされば良いということ。
`(* 2 3 5 7 11 13 17 23)` が `11741730` だし登場する素数の種類自体は多くなさそう。

全体に対する解答からある範囲を切り出したとして、変更があるのは両端の２つの部分列だけだで、両端をその隣とマージ出来るかを判定すれば良さそう。実装が面倒に思えるけど。
いやでも切り出す部分って線形時間にならない・・・？

## "2021-04-29 22-52-16"
> This is a pretty standard problem solvable with the binary lifting technique.

`binary lifting technique` て何？ダブリングのことかな。

## "2021-04-30 17-24-50"
高輪ゲートウェイ駅のスタバにはスマートラウンジなる作業スペース特化みたいな店舗がある。

```
Now, we have the following greedy algorithm: suppose we start at index l; we'll keep extending our first subrange while the condition (every pair of numbers is coprime) is satisfied. We clearly don't gain anything by stopping when we can extend, since every new element just comes with new restrictions. Once we're unable to extend our subrange, we'll start a new subrange, until we reach index r. Now, for every index l, let's define gol to be the first index that will make the condition break when we add it to the subrange. Then, our algorithm is equivalent to starting with an index cur=l, then replacing cur with gocur until we exceed index r. The number of steps it takes is our answer. We now have 2 subproblems to solve:
```

ダブリングだろうと１つの領域を伸ばしていくとしたらクエリあたり線形時間になるんじゃ・・・？何か解釈が間違っていそう。

`DP[i][j]:=i番目を左端として2^j個目の部分列の右端` かな？

+ `DP[i][0]=i番目から始めて最初にGCDが1でなくなるインデックス`
+ `DP[i][1]=i番目から最適に構築して2個目の部分列の右端`
+ `DP[i][2]=i番目から最適に構築して4個目の部分列の右端`

なるほど？クエリがO(logN)になるのかな。

ダブリングの出題頻度がそれ程だとしても何だか難しく感じるなあ。何だろう。木構造でないから？

ダブリングはライブラリにしてあったけどもう使い方を忘れているレベル。

TLE。この問題2秒じゃないのね。

1e5以下の素数が約1e4個あるっぽい。普通に割っていたら1e9かかる。

## "2021-05-01 12-36-16"
配列の要素に積がLCMにならない次の要素を充分高速に探さないといけない。さてどうしたものか。

素数で割るのではなくて約数を列挙すれば√Nだろうか。

TLEは回避できたけれど500msも使っとるぞ。WAなのは1だけ特別扱いすることを忘れていたから。

AC。

考察が足りなかったなあ。
