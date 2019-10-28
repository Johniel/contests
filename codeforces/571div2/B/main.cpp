// codeforces/571div2/B/main.cpp
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

  if (0) {
    set<pair<int, int>> vis;
    for (int i = 1; i <= 7; ++i) {
      for (int j = 1; j <= 7; ++j) {
        vis.insert({i, j});
      }
    }
    each (i, vis) if (i.first <= i.second) cout << i.first << ' ' << i.second << endl;
    return 0;
  }

  lli n, m;
  while (cin >> n >> m) {
    auto fn = [] (lli h, lli w) {
      lli x = (h / 3) * ((w + 1) / 2);

      if (h % 3 == 1) {
        x += (w + 1) / 3;
      }
      if (h % 3 == 2) {
        x += (w + 1) / 2;
      }
      return x;
    };

    cout << max(fn(n, m), fn(m, n)) << endl;
  }

  return 0;
}
