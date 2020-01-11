// codeforces/613div2/C/main.cpp
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

  lli x;
  while (cin >> x) {
    vector<lli> v({1});
    for (lli i = 2; i * i <= x; ++i) {
      lli y = 1;
      while (x % i == 0) {
        y *= i;
        x /= i;
      }
      if (y != 1) v.push_back(y);
    }
    if (x != 1) v.push_back(x);

    lli s, t;
    lli c = 1LL << 62;
    for (int bit = 0; bit < (1 << v.size()); ++bit) {
      lli a, b;
      a = b = 1;
      for (int i = 0; i < v.size(); ++i) {
        if (bit & (1 << i)) {
          a *= v[i];
        } else {
          b *= v[i];
        }
      }
      if (max(a, b) < c) {
        c = max(a, b);
        s = a;
        t = b;
      }
    }
    cout << min(s, t) << ' ' << max(s, t) << endl;
  }

  return 0;
}
