// atcoder/abc055/C/main.cpp
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

  lli n, m;
  while (cin >> n >> m) {

    auto fn = [&] (lli x) {
      lli s = n;
      lli c = m;
      c -= max(0LL, x - s) * 2;
      return x * 2LL <= c;
    };

    lli small = 0;
    lli large = 1LL << 60;
    while (small + 1 < large) {
      lli mid = (small + large) / 2;
      if (fn(mid)) small = mid;
      else large = mid;
    }
    cout << (fn(large) ? large : small) << endl;
  }

  return 0;
}
