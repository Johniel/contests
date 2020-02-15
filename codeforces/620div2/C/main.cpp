// codeforces/620div2/C/main.cpp
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
template<typename P, typename Q> inline pair<Q, P> reverse(pair<P, Q> p) { return make_pair(p.second, p.first); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int _;
  cin >> _;

  int n, ini;
  while (cin >> n >> ini) {
    map<lli, pair<lli, lli>> m;
    for (int i = 0; i < n; ++i) {
      lli t, l, h;
      cin >> t >> l >> h;
      if (m.count(t) == 0) {
        m[t] = make_pair(l, h);
      } else {
        setmax(m[t].first, l);
        setmin(m[t].second, h);
      }
    }

    bool f = true;
    each (i, m) {
      f = f && (i.second.first <= i.second.second);
    }

    lli x = ini;
    lli y = ini;
    lli curr = 0;
    each (i, m) {
      lli diff = abs(i.first - curr);
      const lli l = i.second.first;
      const lli h = i.second.second;

      if (x <= l) {
        x = min(x + diff, l);
      } else {
        x = max(x - diff, l);
      }

      if (y <= h) {
        y = min(y + diff, h);
      } else {
        y = max(y - diff, h);
      }

      f = f && (x <= y);
      f = f && !(y < l || h < x);
      setmin(y, h);
      setmax(x, l);
      curr = i.first;
      // cout << x << ' ' << y << endl;
    }
    cout << (f ? "YES" : "NO") << endl;
  }

  return 0;
}
