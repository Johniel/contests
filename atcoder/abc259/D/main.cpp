// atcoder/abc259/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

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
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  lli s1, s2, t1, t2;
  while (cin >> n >> s1 >> s2 >> t1 >> t2) {
    const int N = 3000 + 3;
    static lli x[N], y[N], r[N];
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i] >> r[i];
    }
    const double eps = 1e-11;
    x[n] = s1;
    y[n] = s2;
    r[n] = 0;
    const int src = n++;
    x[n] = t1;
    y[n] = t2;
    r[n] = 0;
    const int dst = n++;
    static bool g[N][N];
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        lli a = x[i] - x[j];
        lli b = y[i] - y[j];
        lli D = a * a + b * b;

        lli mn = min(r[i], r[j]);
        lli mx = max(r[i], r[j]);

        g[i][j] = g[j][i] = ((mx - mn) * (mx - mn) <= D && D <= (r[i] + r[j]) * (r[i] + r[j]));
      }
    }

    queue<int> q;
    static bool vis[N];
    fill(vis, vis + N, false);
    vis[src] = true;
    for (q.push(src); q.size(); q.pop()) {
      int curr = q.front();
      for (int next = 0; next < n; ++next) {
        if (g[curr][next] && !vis[next]) {
          vis[next] = true;
          q.push(next);
        }
      }
    }
    cout << (vis[dst] ? "Yes" : "No") << endl;
  }

  return 0;
}
