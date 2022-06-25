// atcoder/abc257/D/main.cpp
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
  while (cin >> n) {
    vec<pair<lli, lli>> v(n);
    vec<lli> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i] >> p[i];
    }

    const int N = 200 + 3;
    static bool vis[N];
    auto bfs = [&] (const int src, const lli S) {
      fill(vis, vis + N, false);
      vis[src] = true;
      queue<int> q;
      for (q.push(src); q.size(); q.pop()) {
        const int curr = q.front();
        for (int next = 0; next < n; ++next) {
          if (vis[next]) continue;
          const lli x = v[curr].first - v[next].first;
          const lli y = v[curr].second - v[next].second;
          const lli d = (lli)abs(x) + (lli)abs(y);
          if (p[curr] * S >= d) {
            vis[next] = true;
            q.push(next);
          }
        }
      }
      return count(vis, vis + n, true) == n;
    };

    auto fn = [&] (const lli s) {
      for (int i = 0; i < n; ++i) {
        if (bfs(i, s)) return true;
      }
      return false;
    };

    lli small = 0;
    lli large = 1LL << 32;
    while (small + 1 < large) {
      lli mid = (small + large) / 2;
      if (fn(mid)) large = mid;
      else small = mid;
    }
    if (fn(small)) cout << small << endl;
    else cout << large << endl;
  }

  return 0;
}
