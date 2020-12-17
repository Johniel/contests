// atcoder/arc008/C/main.cpp
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
    double x[n], y[n];
    double t[n], r[n];
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i] >> t[i] >> r[i];
    }

    if (n == 1) {
      cout << 0 << endl;
      continue;
    }

    vec<pair<int, double>> g[n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        double a = x[i] - x[j];
        double b = y[i] - y[j];
        a *= a;
        b *= b;
        g[i].push_back({j, sqrt(a + b) / min(t[i], r[j])});
      }
    }

    priority_queue<pair<double, int>> q;
    q.push({0, 0});
    double cost[n];
    fill(cost, cost + n, 1e128);
    cost[0] = 0;
    while (q.size()) {
      auto p = q.top();
      p.first = abs(p.first);
      q.pop();
      if (cost[p.second] < p.first) continue;
      each (e, g[p.second]) {
        double c = p.first + e.second;
        if (cost[e.first] > c) {
          cost[e.first] = c;
          q.push({-c, e.first});
        }
      }
    }

    double mx = 0;
    sort(cost, cost + n);
    reverse(cost, cost + n);
    for (int i = 0; i < n - 1; ++i) {
      setmax(mx, cost[i] + i);
    }
    cout << mx << endl;
  }

  return 0;
}
