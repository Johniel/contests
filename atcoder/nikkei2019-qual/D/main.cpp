// atcoder/nikkei2019-qual/D/main.cpp
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

const int N = 1e5 + 5;

vec<int> g[N];
int memo[N];
int rec(int curr)
{
  int& ret = memo[curr];
  if (ret != -1) return ret;

  int mx = 0;
  each (next, g[curr]) {
    setmax(mx, rec(next) + 1);
  }
  return ret = mx;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    fill(g, g + N, vec<int>());
    for (int i = 0; i < n + m - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[b].push_back(a);
    }
    static int deg[N];
    fill(deg, deg + N, 0);
    for (int i = 0; i < n; ++i) {
      each (j, g[i]) ++deg[j];
    }
    fill(memo, memo + N, -1);
    for (int i = 0; i < n; ++i) {
      rec(i);
    }
    static int p[N];
    fill(p, p + N, -1);
    for (int i = 0; i < n; ++i) {
      if (g[i].empty()) continue;
      int k = g[i].front();
      each (j, g[i]) {
        if (memo[i] == memo[j] + 1) {
          p[i] = j;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << p[i] + 1 << endl;
    }
  }

  return 0;
}
