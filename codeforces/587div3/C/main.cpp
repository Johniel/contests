// codeforces/587div3/C/main.cpp
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

  vector<lli> v(12);
  while (cin >> v) {
    lli x1 = v[0] * 2;
    lli y1 = v[1] * 2;

    lli x2 = v[2] * 2;
    lli y2 = v[3] * 2;

    lli x3 = v[4] * 2;
    lli y3 = v[5] * 2;

    lli x4 = v[6] * 2;
    lli y4 = v[7] * 2;

    lli x5 = v[8] * 2;
    lli y5 = v[9] * 2;

    lli x6 = v[10] * 2;
    lli y6 = v[11] * 2;

    auto fn = [&] (lli x, lli y) {
      return (x3 <= x && x <= x4 && y3 <= y && y <= y4) || (x5 <= x && x <= x6 && y5 <= y && y <= y6) ;
    };

    bool f = true;
    for (int x = x1; x <= x2; ++x) {
      f = f && fn(x, y1);
      f = f && fn(x, y2);
    }
    for (int y = y1; y <= y2; ++y) {
      f = f && fn(x1, y);
      f = f && fn(x2, y);
    }
    cout << (f ? "NO" : "YES") << endl;
  }

  return 0;
}
