# [From Y to Y](http://codeforces.com/contest/849/problem/C)

同じ文字がN個を結合する場合のコストはN(N-1)/2になる  
異なる文字が混ざっていたとしても、ある文字についてのコストの総和は同じなので、  
事前に個数に対しのコストを列挙しておき、2分探索で長さを決めて文字を追加する。  
コスト0の場合に注意する。

## Code
```cpp
#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  const int N = 1000000;
  lli x[N];
  for (lli i = 0; i < N; ++i) {
    x[i] = (i - 1) * i / 2;
  }

  lli n;
  while (cin >> n) {
    char c = 'a';
    if (n == 0) cout << 'a' << endl;
    while (n) {
      int i = lower_bound(x, x + N, n) - x;
      if (n < x[i]) --i;
      n -= x[i];
      cout << string(i, c++);
    }
    cout << endl;
  }
  
  return 0;
}
```
