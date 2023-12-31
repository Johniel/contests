// atcoder/arc106/A/main.cpp
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

  const __int128 N = 1e18;

  vec<__int128> a;
  a.push_back(1);
  for (int i = 0; i < 70; ++i) {
    a.push_back(a.back() * 3);
    if (N <= a.back()) {
      a.pop_back();
      break;
    }
  }
  vec<__int128> b;
  b.push_back(1);
  for (int i = 0; i < 70; ++i) {
    b.push_back(b.back() * 5);
    if (N <= b.back()) {
      b.pop_back();
      break;
    }
  }
  // cout << a.size() << ' ' << b.size() << endl;
  // cout << a << endl;
  // cout << b << endl;

  lli n_;
  while (cin >> n_) {
    __int128 n = n_;
    bool f = false;
    for (int i = 1; i < a.size(); ++i) {
      for (int j = 1; j < b.size(); ++j) {
        if (n == a[i] + b[j]) {
          cout << i << ' ' << j << endl;
          f = true;
          i = j = 1 << 29;
        }
      }
    }
    if (!f) cout << -1 << endl;
  }

  return 0;
}
