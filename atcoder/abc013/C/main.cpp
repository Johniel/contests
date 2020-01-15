// atcoder/abc013/C/main.cpp
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

  int n, h;
  lli a, b, c, d, e;
  while (cin >> n >> h >> a >> b >> c >> d >> e) {
    lli mn = 1LL << 60;
    for (int i = 0; i <= n; ++i) {
      auto fn = [&] (lli j) {
        return 0 < (b * i + d * j + h) - (n - i - j) * e;
      };
      int small = 0;
      int large = n - i + 1;
      while (small + 1 < large) {
        int mid = (small + large) / 2;
        if (fn(mid)) large = mid;
        else small = mid;
      }
      if (fn(large)) setmin(mn, a * i + c * large);
      if (fn(small)) setmin(mn, a * i + c * small);
    }
    cout << mn << endl;
  }

  return 0;
}
