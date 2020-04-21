// atcoder/abc163/F/main.cpp
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

const int N = 2 * 1e5 + 5;
int color[N];
vec<int> g[N];

int s[N]; // 頂点iを根とする部分木のサイズ
int rec1(int curr, int prev)
{
  int x = 1;
  each (next, g[curr]) {
    if (next == prev) continue;
    x += rec1(next, curr);
  }
  return s[curr] = x;
}

stack<lli> x[N]; // 連結成分の頂点数
lli y[N]; // iを通らないパスの本数
void rec2(int curr, int prev)
{
  stack<lli>& t = x[color[curr]];
  lli z = t.top();
  t.pop();
  t.push(z - s[curr]);

  each (next, g[curr]) {
    if (next == prev) continue;
    t.push(s[next]);
    rec2(next, curr);
    lli z = t.top();
    t.pop();
    y[color[curr]] += z * (z + 1) / 2;
  }

  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  lli n;
  while (cin >> n) {
    fill(g, g + N, vec<int>());
    for (int i = 0; i < n; ++i) {
      cin >> color[i];
      --color[i];
    }

    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    map<int, lli> m;
    for (int i = 0; i < n; ++i) {
      ++m[color[i]];
    }
    fill(y, y + N, 0);

    fill(x, x + N, stack<lli>());
    for (int i = 0; i < n; ++i) {
      x[i].push(n); // 超始点のようなものがあるとすると
    }
    rec1(0, -1);
    rec2(0, -1);

    for (int i = 0; i < n; ++i) {
      if (x[i].size()) {
        lli z = x[i].top();
        y[i] += z * (z + 1) / 2;
      }
    }
    for (int i = 0; i < n; ++i) {
      y[i] = n * (n - 1) / 2 + n - y[i];
    }
    for (int i = 0; i < n; ++i) {
      cout << y[i] << endl;
    }
  }

  return 0;
}
