# ABC163E

ある幼児で嬉しさを最大化しようとするとき、右端か左端のどちらかがに置くのが良い。

配置できる両端の場所がi番目とj番目だとして、次に幼児を配置すべき場所はi+1番目とj番目ori番目とj-1番目になる。

端の方が嬉しさが大きくなるので、(i,j)と(i+1,j)or(i,j-1)ならAiの大きな方の幼児を先に配置すべきとなる。

配置できる範囲を状態にして、Aiの大きな順番で配置するようなDPをする。