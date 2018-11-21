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

lli fn2(lli h, lli w, lli z)
{
  lli x = (h / 2) * w;
  lli y = ((h + 1) / 2) * w;
  return max({x, y, z}) - min({x, y, z});
}

lli fn(lli h, lli w)
{
  lli mn = 1LL << 60;
  for (int i = 1; i < h; ++i) {
    lli a = fn2(h - i, w, i * w);
    lli b = fn2(w, h - i, i * w);
    setmin(mn, min(a, b));
  }
  return mn;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int h, w;
  while (cin >> h >> w) {
    cout << min(fn(h, w), fn(w, h)) << endl;
  }

  return 0;
}
