// atcoder/abc035/B/main.cpp
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

  string s;
  int t;
  while (cin >> s >> t) {
    const int x = count(s.begin(), s.end(), 'R') - count(s.begin(), s.end(), 'L');
    const int y = count(s.begin(), s.end(), 'U') - count(s.begin(), s.end(), 'D');
    const int z = count(s.begin(), s.end(), '?');

    auto fn = [] (int x, int y) { return abs(x) + abs(y); };
    if (t == 1) {
      int mx = 0;
      setmax(mx, fn(x + z, y));
      setmax(mx, fn(x - z, y));
      setmax(mx, fn(x, y - z));
      setmax(mx, fn(x, y + z));
      cout << mx << endl;
    } else {
      int d = fn(x, y);
      if (z <= d) {
        cout << d - z << endl;
      } else {
        cout << (z - d) % 2 << endl;
      }
    }
  }

  return 0;
}
