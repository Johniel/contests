# ARC089

`(i,j)`と`(i+2k,j+2k)`は同じ色になるので、座標それぞれは `mod 2k` する。

また、白の`(i,j)`を黒の`(i+k,j)`か`(i,j+k)`として扱う。

2次元の累積和で角の黒のサイズをK^2通り試す。