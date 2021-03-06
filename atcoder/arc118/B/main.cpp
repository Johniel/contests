// atcoder/arc118/B/main.cpp
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

  int k;
  lli n;
  lli m;
  while (cin >> k >> n >> m) {
    vec<lli> a(k);
    cin >> a;

    auto fn = [&] (lli z) {
      lli p = 0, q = 0;
      vec<pair<lli, lli>> b;
      for (int i = 0; i < a.size(); ++i) {
        lli mai = a[i] * m;
        lli mn = (mai - z + n - 1) / n;
        lli mx = (mai + z) / n;
        // unless (mn < mx) swap(mn, mx);
        b.push_back(make_pair(mn, mx));
        p += mn;
        q += mx;
      }
      // cout << make_pair(z, b) << endl;
      if (p <= m && m <= q) return b;
      else return vec<pair<lli, lli>>();
    };

    lli small = 0;
    lli large = 1LL << 60;
    while (small + 1 < large) {
      lli mid = (small + large) / 2;
      if (fn(mid).size()) large = mid;
      else small = mid;
    }
    vec<pair<lli, lli>> v = fn(large);
    if (v.empty()) v = fn(small);

    vec<lli> b;
    each (i, v) {
      b.push_back(i.first);
      m -= i.first;
    }
    // cout << v << endl;
    // cout << make_pair(m, b) << endl;
    for (int i = 0; i < v.size(); ++i) {
      lli d = min(m, v[i].second - v[i].first);
      b[i] += d;
      m -= d;
    }
    each (i, b) cout << i << ' '; cout << endl;
  }

  return 0;
}
