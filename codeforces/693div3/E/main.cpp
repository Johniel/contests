// codeforces/693div3/E/main.cpp
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

  int _;
  cin >> _;

  int n;
  while (cin >> n) {
    vec<vec<int>> v;
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      if (a < b) swap(a, b);
      v.push_back({a, b, i});
    }
    sort(v.begin(), v.end(), [] (auto a, auto b) {
      if (a[0] != b[0]) return a[0] < b[0];
      return a[1] > b[1];
    });

    // cout << v << endl;

    vec<int> w(n, -2);
    vec<vec<int>> u;
    each (i, v) {
      if (u.empty()) u.push_back(i);
      else {
        while (u.size() && !(u.back()[0] < i[0] && u.back()[1] < i[1])) {
          u.pop_back();
        }
        // cout << u << " -> " << i << endl;
        if (u.size()) {
          w[i[2]] = u.back()[2];
          // w[u.back()[2]] = i[2];
        }
        u.push_back(i);
      }
    }
    each (i, w) cout << i+1 << ' '; cout << endl;
  }

  return 0;
}
