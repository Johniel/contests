# Educational Codeforces Round 107 D
## "2021-04-25 01-14-06"
文字列sで `s[i]==s[j] && s[i+1]==s[j+1]` となるようなインデックスの個数を文字列のコストとする。
nとkが与えられる。aからk種類までのアルファベットを用いてコストが最小になるような長さnの文字列を１つ出力する。

+ n<=2*1e5
+ k<=26

文字列sで隣接する２文字の組の出現回数を抑えればコストも下がる。
26^2よりnが大きくなる場合は同じ文字列を繰り返せば大丈夫でしょきっと。
長ければ削るということで。

アルファベットを頂点、隣接する２文字を辺だと見なして、k頂点の完全グラフで同じ辺を使わないようにして作れる最長のパスか何か？オイラーサイクル？
そんなの簡単に見付ける方法あったかしら。完全グラフだと何かあるのかな。もう分からない。

無闇にDFSしたところで１本のパス（この場合サイクル？）になるような気がしないし。

## "2021-04-25 15-47-23"
うーん。

## "2021-04-27 00-33-50"
頂点数3で描いてみたら割と簡単な感じがする。行き先を文字列の末尾に追加していけば良いだけでは？
```
Input
32 2
Output
aabaabaabaabaabaabaabaabaabaabaa
Answer
aabbaabbaabbaabbaabbaabbaabbaabb
Checker Log
wrong answer the jury's answer is better than the participant's answer
```

駄目でした。

`a→a→b→a` で終わってしまってbbを使えない。

次の行き先を `a` から探すのが駄目？自己ループから始めたらAC。

何だったんだろうこの問題。

## Code
main.cpp
{% raw %}
```cpp
// codeforces/e107/D/main.cpp
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

str s;
int n, k;
set<pair<int, int>> vis;
map<int, int> out;
void rec(int curr)
{
  for (int i = 0; i < k; ++i) {
    int next = (curr + i) % k;
    pair<int, int> e = make_pair(curr, next);
    if (vis.count(e)) continue;
    if (out[next] == k) continue;
    ++out[curr];
    vis.insert(e);
    s += ('a' + next);
    rec(next);
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  while (cin >> n >> k) {
    if (k == 1) {
      cout << str(n, 'a') << endl;
      continue;
    }

    vis.clear();
    s = "a";
    rec(0);
    while (s.size() < n) {
      s = s + s;
    }
    cout << s.substr(0, n) << endl;
  }

  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/codeforces)
+ [repository](https://github.com/Johniel/contests/tree/master/codeforces/e107/D)
