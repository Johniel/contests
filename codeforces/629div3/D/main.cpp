// codeforces/629div3/D/main.cpp
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
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(15);

  int _;
  cin >> _;

  int n;
  while (cin >> n) {
    vec<int> v(n);
    cin >> v;

    bool f = true;
    each (i, v) f = f && (v.front() == i);

    if (f) {
      cout << 1 << endl;
      each (i, v) cout << 1 << ' ' ; cout << endl;
      continue;
    }

    vec<int> u;
    for (int i = 0; i < n; ++i) {
      u.push_back(i % 2);
    }

    if (u.back() == u.front() && v.front() != v.back()) {
      int k = -1;
      for (int i = 0; i + 1 < v.size(); ++i) {
        if (v[i] == v[i + 1]) {
          k = i + 1;
          break;
        }
      }
      if (k == -1) {
        u.back() = 2;
      } else {
        for (int i = k; i < n; ++i) {
          u[i] = (i + 1) % 2;
        }
      }
    }

    set<int> vis;
    each (i, u) vis.insert(i);
    cout << vis.size() << endl;
    each (i, u) cout << i+1 << ' '; cout << endl;
  }

  return 0;
}