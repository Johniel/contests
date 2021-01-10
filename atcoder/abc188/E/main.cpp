// atcoder/abc188/E/main.cpp
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
vec<int> g[N];
vec<lli> a;

const lli inf = 1LL << 60;

lli memo[N];
lli rec(int curr)
{
  lli& ret = memo[curr];
  if (ret != -1) return ret;
  lli mx = -inf;
  each (next, g[curr]) setmax(mx, max(a[next], rec(next)));
  return ret = mx;
}

lli memo2[N];
lli rec2(int curr)
{
  lli& ret = memo2[curr];
  if (ret != inf) return ret;
  lli mn = inf;
  each (next, g[curr]) setmin(mn, rec2(next));
  return ret = mn;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    a.resize(n);
    cin >> a;
    fill(g, g + N, vec<int>());
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      g[x].push_back(y);
    }

    fill(memo, memo + N, -1);
    fill(memo2, memo2 + N, inf);
    lli mx = -inf;
    for (int i = 0; i < n; ++i) {
      setmax(mx, rec(i) - a[i]);
    }
    cout << mx << endl;
  }

  return 0;
}
