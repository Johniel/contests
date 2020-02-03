// atcoder/abc033/D/main.cpp
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

  lli n;
  while (cin >> n) {
    vector<pair<double, double>> v(n);
    cin >> v;

    lli a, b, c;
    a = b = c = 0;
    each (o, v) {
      vector<double> u;
      each (i, v) {
        if (o == i) continue;
        double x = atan2(i.second - o.second, i.first - o.first);
        u.push_back(x);
      }
      // cout << o << endl;
      sort(u.begin(), u.end());
      for (int i = 0; i < n - 1; ++i) {
        u.push_back(u[i] + (M_PI * 2.0));
      }
      // cout << u << endl;
      for (int i = 0; i < n - 1; ++i) {
        double x = u[i] + (M_PI / 2.0);
        double y = u[i] + M_PI;
        const double eps = 1e-10;
        auto itr1 = lower_bound(u.begin(), u.end(), x - eps);
        auto itr2 = upper_bound(u.begin(), u.end(), x + eps);
        auto itr3 = lower_bound(u.begin(), u.end(), y);
        b += itr2 - itr1;
        c += itr3 - itr2;
        // cout << itr2 - itr1 << ", " << x << ' ' << y << endl;
      }
    }
    cout << n*(n-1)*(n-2)/6-(b+c) << ' ' << b << ' ' << c << endl;
    // break;
  }

  return 0;
}
