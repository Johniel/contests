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

  int _t;
  cin >> _t;
  for (int _ = 0; _ < _t; ++_) {
    double n;
    cin >> n;

    double small = 0;
    double large = n;
    for (int loop = 0; loop < 10000; ++loop) {
      double mid = (small + large) / 2;

      double a = mid;
      double b = n - a;

      if (n <= a * b) large = mid;
      else small = mid;
    }

    double a = small;
    double b = n - a;    
    if (abs((a * b) - (a + b)) < 1e-6) {
      printf("Y %.9lf %.9lf\n", a, b);
    } else {
      puts("N");
    }
  }

  return 0;
}
