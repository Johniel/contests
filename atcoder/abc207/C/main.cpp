// atcoder/abc207/C/main.cpp
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
    vec<pair<double, double>> v;
    for (int i = 0; i < n; ++i) {
      int t;
      double a, b;
      cin >> t >> a >> b;
      if (t == 1) {
        v.push_back(make_pair(a, b));
      }
      if (t == 2) {
        v.push_back(make_pair(a, b - 0.1));
      }
      if (t == 3) {
        v.push_back(make_pair(a + 0.1, b));
      }
      if (t == 4) {
        v.push_back(make_pair(a + 0.1, b - 0.1));
      }
    }
    // cout << v << endl;
    set<pair<int, int>> vis;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v.size(); ++j) {
        if (i == j) continue;
        if (v[i].first <= v[j].first && v[j].first <= v[i].second) {
          vis.insert(make_pair(min(i, j), max(i, j)));
        }
        if (v[i].first <= v[j].second && v[j].second <= v[i].second) {
          vis.insert(make_pair(min(i, j), max(i, j)));
        }
      }
    }
    // cout << vis << endl;
    cout << vis.size() << endl;
  }

  return 0;
}
