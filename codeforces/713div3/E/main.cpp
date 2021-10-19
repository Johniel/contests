// codeforces/713div3/E/main.cpp
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

int n, a, b, s;
vec<int> v;
int p;
bool rec(int begin, int x, int sum)
{
  unless (begin + x - 1 <= n) return false;
  if (x == 0) {
    if (sum == s) return true;
    return false;
  }
  int mn = (x - 1) * x / 2;
  mn += (x - 1) * begin;
  int mx = (x - 1) * (x + 1) / 2;
  mx += (x - 1) * (n - x + 1);

  int p = begin + sum + mn;
  int q = begin + sum + mx;
  if (begin == 1 || begin == 2 || begin == 3) {
    // cout << begin << ": " << x << ' ' << make_pair(mn, mx) << ' ' << p << "<=" << s << "<=" << q << ", " << (x - 1) * x / 2 << endl;
  }

  if (p <= s && s <= q) {
    bool b = rec(begin + 1, x - 1, sum + begin);
    if (b) {
      v.push_back(begin);
      return true;
    }
  }

  if (p <= s) {
    return rec(begin + 1, x, sum);
  }

  return false;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  while (cin >> n >> a >> b >> s) {
    // cout << endl;
    int mx = 0;
    for (int i = 0; i < b - a + 1; ++i) {
      mx += n - i;
    }
    if (mx < s) {
      cout << -1 << endl;
      continue;
    }

    --a;
    --b;
    v.clear();
    bool f = rec(1, b - a + 1, 0);
    unless (f) {
      cout << -1 << endl;
      continue;
    }
    vec<int> u(n, -1);
    for (int i = a; i <= b; ++i) {
      u[i] = v[i - a];
    }
    set<int> vis;
    for (int i = 0; i < n; ++i) {
      vis.insert(i+1);
    }
    each (i, u) vis.erase(i);
    for (int i = 0; i < u.size(); ++i) {
      if (u[i] == -1) {
        u[i] = *vis.begin();
        vis.erase(vis.begin());
      }
    }
    each (i, u) cout << i << ' '; cout << endl;
  }

  return 0;
}
