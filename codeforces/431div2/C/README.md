# [From Y to Y](http://codeforces.com/contest/849/problem/C)

同じ文字がN個を結合する場合のコストはN(N-1)/2になる  
異なる文字が混ざっていたとしても、ある文字についてのコストの総和は同じなので、  
事前に個数に対しのコストを列挙しておき、2分探索で長さを決めて文字を追加する。  
コスト0の場合に注意する。
