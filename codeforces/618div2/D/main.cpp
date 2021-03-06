// codeforces/618div2/D/main.cpp
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

  int n;
  while (cin >> n) {
    vec<pair<double, double>> v(n);
    cin >> v;


    bool f = true;
    for (int i = 0; i < n; ++i) {
      int j = (i + (n / 2)) % n;

      double x, y;
      double p, q;
      {
        int k = (i + 1) % n;
        double s = v[i].first - v[k].first;
        double t = v[i].second - v[k].second;
        x = atan2(s, t);
        p = s * s + t * t;
      }
      {
        int k = (j + 1) % n;
        double s = v[k].first - v[j].first;
        double t = v[k].second - v[j].second;
        y = atan2(s, t);;
        q = s * s + t * t;
      }
      // cout << x << ' ' << y << ", " << p << ' ' << q << endl;
      f = f && (abs(x - y) < 1e-8) && (abs(p - q) < 1e-8);
    }
    cout << (f ? "yes" : "no") << endl;
  }

  return 0;
}
