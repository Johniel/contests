// atcoder/abc002/C/main.cpp
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

double heron(double a, double b, double c)
{
  double s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

double dist_pp(double x1, double y1, double x2, double y2)
{
  double x = x1 - x2;
  double y = y1 - y2;
  return sqrt( x * x + y * y );
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  double x1, y1;
  double x2, y2;
  double x3, y3;
  while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
    double a = dist_pp(x1, y1, x2, y2);
    double b = dist_pp(x1, y1, x3, y3);
    double c = dist_pp(x3, y3, x2, y2);
    printf("%.10f\n", heron(a, b, c));
  }

  return 0;
}
