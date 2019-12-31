// atcoder/abc031/C/main.cpp
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

  int n;
  while (cin >> n) {
    vector<int> a(n);
    cin >> a;

    int w = -(1 << 20);
    for (int i = 0; i < n; ++i) {
      int s = -(1 << 29);
      int t = -(1 << 29);
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        int x = 0;
        int y = 0;
        int cnt = 0;
        for (int k = min(i, j); k <= max(i, j); ++k) {
          if (cnt % 2) y += a[k];
          else x += a[k];
          ++cnt;
        }
        if (s < y) {
          s = y;
          t = x;
        }
      }
      setmax(w, t);
    }
    cout << w << endl;
  }

  return 0;
}
