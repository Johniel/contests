// github.com/Johniel/contests
// atcoder/abc320/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

const int N = 2 * 1e5 + 3;
vec<pair<int, pair<lli, lli>>> g[N];

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    fill(g, g + N, vec<pair<int, pair<lli, lli>>>());
    for (int i = 0; i < m; ++i) {
      int a, b, x, y;
      cin >> a >> b >> x >> y;
      --a;
      --b;
      g[a].push_back(make_pair(b, make_pair(x, y)));
      g[b].push_back(make_pair(a, make_pair(-x, -y)));
    }

    vec<pair<lli, lli>> v(n, make_pair(0, 0));
    set<int> vis;
    vis.insert(0);
    queue<int> q;
    for (q.push(0); q.size(); q.pop()) {
      int curr = q.front();
      each (e, g[curr]) {
        auto [next, diff] = e;
        unless (vis.count(next)) {
          vis.insert(next);
          v[next].first = v[curr].first + diff.first;
          v[next].second = v[curr].second + diff.second;
          q.push(next);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      if (vis.count(i)) cout << v[i].first << ' ' << v[i].second << endl;
      else cout << "undecidable" << endl;
    }
  }
  return 0;
}
