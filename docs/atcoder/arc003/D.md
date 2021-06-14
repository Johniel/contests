# ARC003 D
誤差2e-3は大きすぎる。しかしこれはどうやって解けば良いものか。

---

まさかの乱択。これは現行では出題されないでしょう。
実行時間10秒を見落としていた。気付いていたら乱択に思い至ったかな。

直近のACされた提出を見ていて[偶然見付けた](https://atcoder.jp/contests/arc003/submissions/23270237)。随分と長いテンプレートを使っている人もいるんだな。

## Code
main.cpp
{% raw %}
```cpp
// atcoder/arc003/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  srand(time(NULL));

  int n, m, k;
  while (cin >> n >> m >> k) {
    const int M = 12;
    bool taboo[M][M];
    fill(&taboo[0][0], &taboo[M - 1][M - 1] + 1, false);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      taboo[a][b] = taboo[b][a] = true;
    }

    vec<int> a;
    for (int i = 0; i < n; ++i) {
      a.push_back(i);
    }

    vec<pair<int, int>> u;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        u.push_back(make_pair(i, j));
      }
    }

    double p = 0;
    const int N = 1000000;
    for (int _ = 0; _ < N; ++_) {
      vec<int> b = a;
      for (int _k = 0; _k < k; ++_k) {
        int i = rand() % u.size();
        swap(b[u[i].first], b[u[i].second]);
      }
      bool f = true;
      for (int i = 0; i < b.size() && f; ++i) {
        int j = (i + 1) % b.size();
        f = f && !taboo[b[i]][b[j]];
      }
      p += f;
    }
    cout << p / N << endl;
  }

  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/arc003/D)
