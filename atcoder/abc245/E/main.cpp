// atcoder/abc245/E/main.cpp
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
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    vec<pair<int, int>> x(n), y(m);

    each (i, x) cin >> i.first;
    each (i, x) cin >> i.second;
    each (i, y) cin >> i.first;
    each (i, y) cin >> i.second;

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    multiset<int> s;
    bool f = true;
    for (int i = 0, j = 0; i < x.size(); ++i) {
      while (j < y.size() && x[i].first <= y[j].first) {
        s.insert(y[j].second);
        ++j;
      }
      auto itr = s.lower_bound(x[i].second);
      if (itr == s.end()) {
        f = false;
        break;
      }
      s.erase(itr);
    }
    cout << (f ? "Yes" : "No") << endl;
  }

  return 0;
}
