// codeforces/618div2/E/main.cpp
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
  // while (cin >> n) {
  while (scanf("%d", &n) == 1) {
    const int N = 1e6 + 5;
    // vector<double> a(n); cin >> a;
    static double a[N];
    for (int i = 0; i < n; ++i) {
      // cin >> a[i];
      scanf("%lf", a + i);
    }

    // vec<pair<double, int>> v;
    static pair<double, int> v[N];
    int idx = 0;
    // each (i, a) {
    for (int _ = 0; _ < n; ++_) {
      const double i = a[_];
      // v.push_back(make_pair(i, 1));
      v[idx++] = make_pair(i, 1);
      // while (1 < v.size()) {
      while (1 < idx) {
        // pair<double, int> x = v.back(); v.pop_back();
        // pair<double, int> y = v.back(); v.pop_back();
        pair<double, int> x = v[--idx];
        pair<double, int> y = v[--idx];
        int d = x.second + y.second;
        double c = (x.first * x.second + y.first * y.second) / d;
        if (c <= y.first) {
          // v.push_back(make_pair(c, d));
          v[idx++] = make_pair(c, d);
        } else {
          // v.push_back(y);
          // v.push_back(x);
          v[idx++] = y;
          v[idx++] = x;
          break;
        }
      }
    }

    for (int i = 0; i < idx; ++i) {
      for (int j = 0; j < v[i].second; ++j) {
        printf("%.10lf\n", v[i].first);
      }
    }
    // each (i, v) {
    //   for (int j = 0; j < i.second; ++j) {
    //     printf("%.10lf\n", i.first);
    //   }
    // }
  }

  return 0;
}
