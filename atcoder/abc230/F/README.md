# AtCoder Beginner Contest 230 F - Predilection
サンプル１の `+1, -1, +1` の累積和を考える。不要かもしれないけれど、いつも通り長さ0の区間を表現するために先頭に0が入っているとして、 `0, +1, 0, +1` になる。
仮に最初の `+1` と `-1` を足したとすると `0, +1` になり累積和は `0, 0, +1` に。
何が言いたいかというと、ある２つの隣接する数字を足す操作は、累積和上では要素の削除に相当するということ。
あとは累積和の部分列が何通りあるかを数えると答え。
気付かないでしょうこれ難しい。
