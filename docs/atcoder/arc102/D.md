# ARC102 D
2^xと0の重みを持つ２辺を２頂点間に作る。

すると、その範囲で0から2^p-1までの数を表現できる。

その後はLのビットの立っている部分を補うように辺を作る。

例えば、Lが(10101)2なら、重み(10000)2の辺を0から2^2-1の頂点へ、重み(10100)2の辺を0から2^1-1の頂点へ作る。

図を書かないと分からないかもしれない。

---

なぜ本番中に解けなかったのか悔やまれる。


## Codes
main.cpp
{% raw %}{{
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

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int L;
  while (cin >> L) {
    int x = 0;
    for (int i = 0; (1 << i) <= L; ++i) {
      if (L & (1 << i)) {
        x = i;
      }
    }

    vector<tuple<int, int, int>> es;
    for (int i = 0; i < x; ++i) {
      es.push_back(make_tuple(i, i + 1, 1 << (x - i - 1)));
      es.push_back(make_tuple(i, i + 1, 0));
    }

    int y = 1 << x;
    for (int i = 0; i < x; ++i) {
      if (L & (1 << i)) {
        es.push_back(make_tuple(0, x - i, y));
        y += 1 << i;
      }
    }

    set<int> v;
    each (e, es) {
      v.insert(get<0>(e));
      v.insert(get<1>(e));
    }
    cout << v.size() << ' ' << es.size() << endl;
    each (e, es) {
      cout << get<0>(e) + 1 << ' ' << get<1>(e) + 1 << ' ' << get<2>(e) << endl;
      assert(get<0>(e) < get<1>(e));
    }
  }
  
  return 0;
}
}}{% endraw %}
```
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/arc102/D)
