// codeforces/e125/D/main.cpp
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

  int n, c;
  while (cin >> n >> c) {
    vec<vec<lli>> vs(n, vec<lli>(3));
    cin >> vs;

    const int N = 1e6 + 3;
    const lli inf = 1LL << 60;

    static lli x[N];
    fill(x, x + N, -inf);
    each (v, vs) x[v[0]] = v[1] * v[2];

    for (lli i = 1; i < N; ++i) {
      if (abs(x[i]) == inf) continue;
      for (lli j = 1; i * j < N; ++j) {
        setmax(x[i * j], x[i] * j);
      }
    }

    for (int i = 0; i + 1 < N; ++i) {
      setmax(x[i + 1], x[i]);
    }

    int m;
    cin >> m;
    while (m--) {
      lli d, h;
      cin >> d >> h;
      int z = lower_bound(x + 1, x + c + 1, d * h + 1) - x;
      if (c < z) cout << -1 << ' ';
      else cout << z << ' ';
    }
    cout << endl;
  }

  return 0;
}
