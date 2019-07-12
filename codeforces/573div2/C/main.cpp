// codeforces/573div2/C/main.cpp
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

  lli n, m, k;
  while (cin >> n >> m >> k) {
    vector<lli> v(m);
    cin >> v;

    int cnt = 0;
    lli x = k;
    int y = 0;
    for (int i = 0; i < v.size(); ++i) {
      // cout << x << ' ' << v[i] << endl;
      if (x < v[i]) {
        if (y) {
          ++cnt;
          x += y;
          y = 0;
        } else {
          lli tmp = x;
          x += ((v[i] - x) / k) * k;
          if (tmp == x) x += k;
        }
        --i;
      } else {
        ++y;
      }
    }
    if (y) ++cnt;
    cout << cnt << endl;
  }

  return 0;
}
