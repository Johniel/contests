# AtCoder Regular Contest 140 B - Shorten ARC
unrated参加。本番メモ。

+ 何だかtopcoderっぽさを感じる問題だなあ。
+ 操作可能な箇所が複数あったとして、対象とする順番が結果に影響するか考える。
+ でもこれ、A...ARC...Cみたいな文字列をSから探すだけでは・・・？
+ 偶数奇数の成約があるからそれぞれのA...ARC...Cの長さを考えないと行けないけれど。ひとまず全て偶数回操作するのかな。
  + `ARCARC` が2回。
  + `ARCAARCC` が3回。
+ A...AC...Cは関係ある？
  + 無いと思った。
+ [AC3+13,WA5,RE10](https://atcoder.jp/contests/arc140/submissions/31720184)。
  + 空列の判定が足りてない。
    + [変化なし](https://atcoder.jp/contests/arc140/submissions/31720531)。
    + [REが消えた](https://atcoder.jp/contests/arc140/submissions/31720784)。
+ `ARCARCARC` のサンプルか。
  + `ARC,ARC,ARC`→`R,ARC,ARC`→`R,AC,ARC`→`R,AC,R`
  + `AARCC,ARC,ARC`→`ARC,ARC,ARC`→`AC,ARC,ARC`→`AC,R,ARC`→`AC,R,AC`
  + AとCの個数の偶奇で変わる。最初から気付け。
  + [AC3+10,WA18](https://atcoder.jp/contests/arc140/submissions/31723700)。
    + 悪化してるよもう。
+ `AARCCAARCC` でもう一度。
  + `AARCC,AARCC`→`ARC,AARCC`→`AC,AARCC`→`AC,ARC`→`AC,AC`
+ `AAARCCCAARCC`
  + `AAARCCC,AARCC`→`AARCC,AARCC`→`AACC,AARCC`→
  + あ、何か根本的な誤解がある気がする。
    + `AAARCCC,AARCC`→`AARCC,AARCC`→`AACC,AARCC`→`AACC,ARC`→`AACC,AC`
    + `AAARCCC,AARCC`→`AARCC,AARCC`→`AARCC,AACC`→`ARC,AACC`→`AC,AACC`
+ もしかして1つのA...ARC...Cについて最大で2回までしか操作出来ないとか？
  + [WA](https://atcoder.jp/contests/arc140/submissions/31725138)。
  + unratedだからって雑になってきている。
  + ARCだけ特別扱いなのかやはり？うーん。
  + `ARC,ARC,ARC,AAARCCC`→`ARC,ARC,ARC,AARCC`→`ARC,ARC,AC,AARCC`→`ARC,ARC,AC,ARC`→`ARC,AC,AC,ARC`→`ARC,AC,AC,R`→`AC,AC,AC,R`
  + が、駄目。[AC3+8,WA20](https://atcoder.jp/contests/arc140/submissions/31727355)。
+ timeup

---

解説を読む。`min(2M,∑X)` より前（つまり答え以外）は想定通り。証明よりも、どういった順序で思考すればこの式に辿り着くかを説明してくれないかな。

`ARCだけ特別扱いする` と `最大2回` の2通りのアプローチの小さい方というのが答え。それぞれは考えついていたので残念。
