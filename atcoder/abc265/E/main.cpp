// github.com/Johniel/contests
// atcoder/abc265/E/main.cpp

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
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  lli a, b, c, d, e, f;
  while (cin >> n >> m >> a >> b >> c >> d >> e >> f) {
    vec<pair<lli, lli>> v(m);
    cin >> v;
    sort(v.begin(), v.end());

    vec<pair<lli, lli>> dir({make_pair(a, b), make_pair(c, d), make_pair(e, f)});

    const int N = 300 + 3;
    map<pair<lli, lli>, lli> dp[N];
    dp[0][make_pair(0, 0)] = 1;
    for (int i = 0; i < n; ++i) {
      each (j, dp[i]) {
        pair<lli, lli> p = j.first;
        each (k, dir) {
          lli x = p.first + k.first;
          lli y = p.second + k.second;
          auto z = make_pair(x, y);
          if (binary_search(v.begin(), v.end(), z)) continue;
          (dp[i + 1][z] += j.second) %= mod;
        }
      }
    }
    lli z = 0;
    each (i, dp[n]) {
      (z += i.second) %= mod;
    }
    cout << z << endl;
  }

  return 0;
}
