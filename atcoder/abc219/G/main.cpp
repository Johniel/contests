// github.com/Johniel/contests
// atcoder/abc219/G/main.cpp

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
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

const int N = 2 * 1e5 + 3;
vec<int> g[N];
vec<int> small[N];
vec<int> large[N];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m, q;
  while (cin >> n >> m >> q) {
    fill(g, g + N, vec<int>());
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vec<int> v(q);
    cin >> v;
    each (i, v) --i;

    const int B = ceil(sqrt(m));

    fill(large, large + N, vec<int>());
    fill(small, small + N, vec<int>());
    for (int i = 0; i < n; ++i) {
      if (B <= g[i].size()) {
        each (j, g[i]) {
          if (B <= g[j].size()) large[i].push_back(j);
        }
      } else {
        each (j, g[i]) small[i].push_back(j);
      }
    }

    vec<int> x(n);
    iota(x.begin(), x.end(), 0);
    vec<pair<int, int>> memo(n, {-1, -1});

    // ok
    // 次数小→次数＊, small
    // 次数大→次数大, large
    // ng
    // 次数大→次数小
    auto update = [&] (int i) {
      each (j, small[i]) {
        if (B <= g[j].size() && memo[i].first < memo[j].first) {
          memo[i] = memo[j];
          x[i] = memo[j].second;
        }
      }
      return x[i];
    };

    for (int nth = 0; nth < q; ++nth) {
      const int i = v[nth];
      if (B <= g[i].size()) {
        each (j, large[i]) x[j] = x[i];
        memo[i] = {nth, x[i]};
      } else {
        update(i);
        each (j, g[i]) {
          x[j] = x[i];
          unless (B <= g[j].size()) memo[j].first = nth;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      unless (B <= g[i].size()) update(i);
    }
    each (i, x) cout << i + 1 << ' '; cout << endl;
  }

  return 0;
}
