# AGC026 B
解説を読んでもなお難しかった。

---

数パターンは自明なケースがある。
+ AがBより小さいと最初に買えないのでNo
+ DがBより小さいと消費に供給が追いつかないのでNo
+ CがBより大きいと常にBより在庫が多くなるのでYes

そうでない場合、CBDの大小関係は`C < B <= D` になる。<br />
答えがは、現在の在庫数が`C`と`B`の間になるかどうかで決まり、なるなら`No`でならないなら`Yes`。

最初に在庫が追加されるのは、在庫をBずつ減らしてC以下になるときなので、その個数はA%Bになる。※A%Bが`C`より大きければそれまで<br />
同様に、その次に在庫が追加されるのは、(A%B+D)%B個の時になる。

つまり、`mod B`の世界で`A`に`D`ずつ足していき`C`を超えることがあるかどうかを判定すれば良い。（この時点でだいぶ賢い）

`A=B`の場合を始めに考えてみる。Bずつ減るので、1度目の追加は在庫0のとき、2度目は在庫D%Bの時、2度目は在庫D%Bの時、3度目は在庫(D%B)+(D%B)の時になる。<br/>
`(D%B)+...+(D%B)`が`B`を超えるときが重要で、この時に残りの在庫数が、`B%(D%B)+...+(D%B)`になる。<br/>
例えば、`A=7,B=7,C=6,D=9`なら、在庫追加のタイミングは*0個*、2個、4個、6個、*1個*、3個となる。

この順にmodを取る流れはまさにGCDで、在庫追加のタイミングの個数はGCD間隔になる。（だいぶ賢い）<br/>
上記からもう少し表現を変えると、`mod B`の世界で`A`に`GCD(B,D)`ずつ足していき`C`を超えることがあるかどうかを判定すれば良い。

`A=B`の場合では`mod B`の正解での最大値は`B-GCD`になる。そうでない場合の`A`をどう扱うべきかというと、増加がGCD区切りになるので`A%GCD`として扱えば良い。<br/>
つまり、`(A%GCD)+(B-GCD)`と`C`の比較で`Yes`か`No`かが分かる。

## Code
main.cpp
{% raw %}
```cpp
#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  while (cin >> t) {
    while (t--) {
      lli A, B, C, D;
      cin >> A >> B >> C >> D;

      if (0) ;
      else if (A < B) cout << "No" << endl;
      else if (D < B) cout << "No" << endl;
      else if (B <= C) cout << "Yes" << endl;
      else {
        lli g = __gcd(B, D);
        lli mx = (A % g) + (B - g);
        cout << (C < mx ? "No" : "Yes") << endl;
      }
    }
  }
  
  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/agc026/B)
