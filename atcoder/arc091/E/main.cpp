// atcoder/arc091/E/main.cpp
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

  int n, a, b;
  while (cin >> n >> a >> b) {
    vec<int> v[b];
    int x = n;
    int y = b - 1;
    for (int i = 0; i < b && x; ++i) {
      for (int j = 0; j < a && x; ++j) {
        v[i].push_back(x--);
        if (x == y) break;
      }
      --y;
    }

    // for (int i = 0; i < b; ++i) cout << v[i] << endl;

    if (v[b - 1].empty()) {
      cout << -1 << endl;
      continue;
    }
    if (v[0].size() != a) {
      cout << -1 << endl;
      continue;
    }

    vec<int> u;
    for (int i = 0; i < b; ++i) {
      while (v[i].size()) {
        u.push_back(v[i].back());
        v[i].pop_back();
      }
    }

    if (u.size() != n) {
      cout << -1 << endl;
      continue;
    }

    for (int i = 0; i < u.size(); ++i) {
      if (i) cout << ' ';
      cout << u[i];
    }
    cout << endl;
  }
  return 0;
}
