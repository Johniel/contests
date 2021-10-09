// atcoder/abc222/E/main.cpp
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
constexpr lli mod = 998244353;

const int N = 1000 + 4;
vec<int> g[N];

map<pair<int, int>, int> cnt;
bool rec(int curr, int prev, int dst)
{
  if (curr == dst) return true;
  each (next, g[curr]) {
    if (next == prev) continue;
    if (rec(next, curr, dst)) {
      ++cnt[make_pair(curr, next)];
      return true;
    }
  }
  return false;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m, k;
  while (cin >> n >> m >> k) {
    cnt.clear();
    fill(g, g + N, vec<int>());
    vec<int> a(m);
    cin >> a;
    each (i, a) --i;

    vec<pair<int, int>> es;
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      g[x].push_back(y);
      g[y].push_back(x);
      es.push_back(make_pair(min(x, y), max(x, y)));
    }

    for (int i = 0; i + 1 < a.size(); ++i) {
      rec(a[i], -1, a[i + 1]);
    }

    vec<int> w(es.size(), 0);
    for (int i = 0; i < es.size(); ++i) {
      pair<int, int> p = es[i];
      pair<int, int> q = make_pair(es[i].second, es[i].first);
      w[i] = cnt[p] + cnt[q];
    }

    const int K = 1e5 + 3;
    static lli dp[N][K];
    fill(&dp[0][0], &dp[N - 1][K - 1] + 1, 0);
    dp[0][0] = 1;
    for (int i = 0; i < es.size(); ++i) {
      for (int j = 0; j < K; ++j) {
        if (j + w[i] < K) (dp[i + 1][j + w[i]] += dp[i][j]) %= mod;
        (dp[i + 1][j] += dp[i][j]) %= mod;
      }
    }

    const lli z = accumulate(w.begin(), w.end(), 0LL);
    if ((z + k) % 2) cout << 0 << endl;
    else if (z - k < 0) cout << 0 << endl;
    else cout << dp[es.size()][(z + k) / 2] << endl;
  }

  return 0;
}
