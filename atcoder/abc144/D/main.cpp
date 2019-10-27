// atcoder/abc144/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  double a, b, x;
  while (cin >> a >> b >> x) {
    if (x < (a * a * b) / 2.0) {
      double c = 2.0 * x / (a * b);
      double r = atan(b / c);
      printf("%.10lf\n", r * 180.0 / M_PI);
    } else {
      double c = 2.0 * (a * a * b - x) / (a * a);
      double r = atan(c / a);
      printf("%.10lf\n", r * 180.0 / M_PI);
    }
  }

  return 0;
}
