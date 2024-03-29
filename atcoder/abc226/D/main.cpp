// atcoder/abc226/D/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<pair<lli, lli>> v(n);
    cin >> v;
    const int N = 500 + 3;
    pair<lli, lli> g[N][N];
    const lli inf = 1LL << 60;
    fill(&g[0][0], &g[N - 1][N - 1] + 1, make_pair(inf, inf));

    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v.size(); ++j) {
        if (i == j) continue;
        lli x = v[i].first - v[j].first;
        lli y = v[i].second - v[j].second;
        if (0) ;
        else if (x == 0) g[i][j] = make_pair(0, y / abs(y));
        else if (y == 0) g[i][j] = make_pair(x / abs(x), 0);
        else {
          lli z = __gcd(abs(x), abs(y));
          g[i][j] = {x / z, y / z};
        }
      }
    }

    set<pair<lli, lli>> vis;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (g[i][j].first != inf) vis.insert(g[i][j]);
      }
    }
    cout << vis.size() << endl;

    // for (int i = 0; i < n; ++i) {
    //   for (int j = 0; j < n; ++j) {
    //     if (g[i][j].first != inf) cout << g[i][j] << ' ';
    //     else cout << "(_,_) ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;
  }

  return 0;
}
