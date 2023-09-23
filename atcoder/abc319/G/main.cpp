// github.com/Johniel/contests
// atcoder/abc319/G/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (const auto p = make_pair(_i, c.at(_i)); true)
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

namespace math {
  lli extgcd(lli a, lli b, lli& x, lli& y)
  {
    lli g = a;
    x = 1;
    y = 0;
    if (b != 0) {
      g = extgcd(b, a % b, y, x);
      y -= (a / b) * x;
    }
    return g;
  }

  lli mod_inverse(lli a, lli m)
  {
    lli x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
  }

  lli mod_pow(lli n, lli p, lli M = mod)
  {
    if (p == 0) return 1;
    if (p == 1) return n % M;
    lli m = mod_pow(n, p / 2, M);
    m *= m;
    m %= M;
    if (p % 2) m = (m * n) % M;
    return m;
  }
};

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    vec<pair<int, int>> v(m);
    cin >> v;
    each (i, v) --i.first, --i.second;
    sort(v.begin(), v.end());

    map<int, vec<int>> rmed;
    each (i, v) {
      rmed[i.first].push_back(i.second);
      rmed[i.second].push_back(i.first);
    }

    vec<int> dist(n, -1);
    dist[0] = 0;
    vec<lli> sum(n, 0);
    sum[0] = 1;
    vec<lli> w(n, 0);
    w[0] = 1;
    queue<int> q;
    set<int> candidates;
    for (int i = 1; i < n; ++i) candidates.insert(i);
    for (q.push(0); q.size(); q.pop()) {
      int curr = q.front();
      auto c = candidates;
      each (next, c) {
        if (dist[next] != -1) continue;
        if (binary_search(v.begin(), v.end(), make_pair(curr, next))) continue;
        if (binary_search(v.begin(), v.end(), make_pair(next, curr))) continue;
        candidates.erase(next);
        q.push(next);
        dist[next] = dist[curr] + 1;
        lli r = 0;
        each (k, rmed[next]) {
          if (dist[next] == dist[k] + 1) (r += w[k]) %= mod;
        }
        lli x = (sum[dist[curr]] - r + mod) % mod;
        // cout << next+1 << ":" << sum[dist[curr]] << "-" << r << endl;
        w[next] = x;
        (sum[dist[next]] += x) %+ mod;
      }
    }
    // cout << dist << endl;
    // cout << sum << endl;
    // cout << w << endl;
    if (dist[n - 1] == -1) {
      cout << -1 << endl;
      continue;
    }
    // cout << sum[dist[n - 1]] << endl;
    cout << w[n - 1] << endl;
  }
  return 0;
}
