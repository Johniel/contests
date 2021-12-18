# Codeforces Round #748 (Div. 3) G. Changing Brackets
括弧の向きを変えることにコストがかからないということは種類だけ気にすれば良いはず。
()を消しても[]がvalidな、[]を消しても()がvalidなbrackets sequenceになるはずだから、()の間に[]は偶数個あるし、[]の間にも()は偶数個あるはず。
種類が2つあるけれど同じ問題なので片方が解ければ良い。
ある領域に偶数個か奇数個かなんてどうやって判定するんだ。


解説を見る。

なるほど、偶数個目と奇数個目を別々にカウントして同数か見るのか賢い。しかも一方の種類だけ気にすれば確かに十分だ。

AC。