# [Codeforces Round #715 Div. 2 C. The Sports Festival](https://codeforces.com/contest/1509/problem/C)
## "2021-05-16 18-24-04"
これは確か本番で解けなかったやつ。

n<=2000個の要素を持つ配列aが与えられる。di=max(a1,a2,…,ai)−min(a1,a2,…,ai)とした時、aを好きに並べ替えてΣdiの最小値を答えなさい。

解いている人数からしてかなり簡単なはずDiv2のCだし。

何も考えずに最大値を最小値に注目して考えてみる。数値の重複は存在しないもののする。
`最大-最小` なんだし、最大値と最小値が出現して以降は全て `最大-最小` となるはず。
diの最大値としてありえる数値が `最大-最小` だから最大値か最小値で使われていない方は極力後回しにした方が良いはず。
仮に末尾が最大値だとして、その直前までは `２番目に大きな値-最小値` のはず。

## その前は？
`２番目に大きな値-最小値` の前は `3番目に大きな値-最小値` or `２番目に大きな値-２番目に大小さな値`

これもしかして両脇から削るように２択をしていけば良いだけ？いかにもそれらしいNの上限だし。

Accepted。

## Code
main.cpp
{% raw %}
```cpp
// codeforces/715div2/C/main.cpp
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

vec<lli> a;
const int N = 2000 + 3;
lli memo[N][N];
lli rec(int i, int j)
{
  if (i == j) return 0;
  lli& ret = memo[i][j];
  if (ret != -1) return ret;
  return ret = a[j - 1] - a[i] + min(rec(i + 1, j), rec(i, j - 1));
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    a.resize(n);
    cin >> a;
    sort(a.begin(), a.end());
    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);
    cout << rec(0, a.size()) << endl;
  }

  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/codeforces)
+ [repository](https://github.com/Johniel/contests/tree/master/codeforces/715div2/C)
