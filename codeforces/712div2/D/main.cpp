// codeforces/712div2/D/main.cpp
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
    vec<pair<int, int>> b, w;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if ((i + j) % 2) {
          b.push_back(make_pair(i, j));
        } else {
          w.push_back(make_pair(i, j));
        }
      }
    }

    for (int i = 0; i < n * n; ++i) {
      int x;
      cin >> x;
      if (x == 1) {
        if (b.size()) {
          cout << 2 << ' ' << b.back().first + 1 << ' ' << b.back().second + 1 << endl;
          b.pop_back();
        } else {
          cout << 3 << ' ' << w.back().first + 1 << ' ' << w.back().second + 1 << endl;
          w.pop_back();
        }
      }
      if (x == 2) {
        if (w.size()) {
          cout << 1 << ' ' << w.back().first + 1 << ' ' << w.back().second + 1 << endl;
          w.pop_back();
        } else {
          cout << 3 << ' ' << b.back().first + 1 << ' ' << b.back().second + 1 << endl;
          b.pop_back();
        }
      }
      if (x == 3) {
        if (w.size()) {
          cout << 1 << ' ' << w.back().first + 1 << ' ' << w.back().second + 1 << endl;
          w.pop_back();
        } else {
          cout << 2 << ' ' << b.back().first + 1 << ' ' << b.back().second + 1 << endl;
          b.pop_back();
        }
      }
    }
  }

  return 0;
}
