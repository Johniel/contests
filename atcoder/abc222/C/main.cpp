// atcoder/abc222/C/main.cpp
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

  int n, m;
  while (cin >> n >> m) {
    char g[2 * n][m];
    for (int i = 0; i < 2 * n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> g[i][j];
      }
    }

    priority_queue<pair<int, int>> q;
    for (int i = 0; i < 2 * n; ++i) {
      q.push(make_pair(0, -i));
    }

    for (int i = 0; i < m; ++i) {
      vec<pair<int, int>> v;
      while (q.size()) {
        auto x = q.top(); q.pop();
        auto y = q.top(); q.pop();

        if (g[abs(x.second)][i] == 'G' && g[abs(y.second)][i] == 'C') ++x.first;
        if (g[abs(x.second)][i] == 'C' && g[abs(y.second)][i] == 'P') ++x.first;
        if (g[abs(x.second)][i] == 'P' && g[abs(y.second)][i] == 'G') ++x.first;

        if (g[abs(y.second)][i] == 'G' && g[abs(x.second)][i] == 'C') ++y.first;
        if (g[abs(y.second)][i] == 'C' && g[abs(x.second)][i] == 'P') ++y.first;
        if (g[abs(y.second)][i] == 'P' && g[abs(x.second)][i] == 'G') ++y.first;

        v.push_back(x);
        v.push_back(y);
      }
      each (i, v) q.push(i);
    }
    while (q.size()) {
      cout << abs(q.top().second) + 1 << endl;
      q.pop();
    }
  }

  return 0;
}
