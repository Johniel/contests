// atcoder/abc139/F/main.cpp
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

double A(pair<double, double> p) {
  return atan2(p.first, p.second);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<pair<double, double>> v(n);
    cin >> v;
    sort(v.begin(), v.end(), [] (auto i, auto j) { return A(i) < A(j); });
    double mx = 0;
    for (int i = 0; i < v.size(); ++i) {
      pair<double, double> p = {0, 0};
      for (int j = 0; j < v.size(); ++j) {
        p.first += v[(i + j) % v.size()].first;
        p.second += v[(i + j) % v.size()].second;
        setmax(mx, sqrt(p.first * p.first + p.second * p.second));
      }
    }
    printf("%.20lf\n", mx);
  }

  return 0;
}
