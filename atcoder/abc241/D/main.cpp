// atcoder/abc241/D/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    multiset<lli> vis;
    for (int _ = 0; _ < n; ++_) {
      // cout << ">> "; each (i, vis) cout << i << ' '; cout << endl;
      lli op, x, k;
      cin >> op >> x;
      if (op == 1) {
        vis.insert(x);
      }
      if (op == 2) {
        cin >> k;
        auto itr = vis.lower_bound(x + 1);
        bool f = true;
        for (int j = 0; j < k; ++j) {
          if (itr == vis.begin()) {
            f = false;
            break;
          }
          --itr;
        }
        if (f) cout << *itr << endl;
        else cout << -1 << endl;
      }
      if (op == 3) {
        cin >> k;
        auto itr = vis.lower_bound(x);
        bool f = true;
        for (int j = 0; j < k-1; ++j) {
          if (itr == vis.end()) {
            f = false;
            break;
          }
          ++itr;
        }
        if (f && itr != vis.end()) cout << *itr << endl;
        else cout << -1 << endl;
      }
    }
  }

  return 0;
}
