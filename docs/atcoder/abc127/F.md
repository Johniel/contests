# ABC127: F

from: https://drken1215.hatenablog.com/entry/2019/06/15/114700
```
そしてこれは実は有名問題なのだ。実は a0,a1,…,an−1 が小さい順にソートされていると仮定したとき、その中央値 (メディアン) になるのだ。
```

えー、知らなかった。もう老人だし忘れていたのかもしれないけれど。

priority_queueで大きい方と小さい方を管理する。その中身が全てxより大きいか小さいかも分かるので合計値も計算しておく。

## Code
main.cpp
{% raw %}
```cpp
// atcoder/abc127/F/main.cpp
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

  int q;
  while (cin >> q) {
    priority_queue<int, vector<int>, greater<int>> large;
    priority_queue<int, vector<int>, less<int>> small;
    lli l = 0;
    lli s = 0;
    lli sumb = 0;
    while (q--) {
      int op, a, b;
      cin >> op;
      if (op == 1) {
        cin >> a >> b;
        sumb += b;
        if (large.size() < small.size()) {
          large.push(a);
          l += a;
        } else {
          small.push(a);
          s += a;
        }
        if (large.size() && small.size()) {
          while (large.top() < small.top()) {
            int p = large.top(); large.pop();
            int q = small.top(); small.pop();
            l -= p; l += q; large.push(q);
            s -= q; s += p; small.push(p);
          }
        }
      }
      if (op == 2) {
        lli x = small.top();
        lli p = l - x * large.size();
        lli q = x * small.size() - s;
        cout << x << ' ' << p + q + sumb << endl;
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
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/abc127/F)
