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

  int n, y;
  while (cin >> n >> y) {
    // 10000
    // 5000
    // 1000
    // 10, 5, 1
    y /= 1000;
    bool f = false;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        int k = y - (5 * i) - (10 * j);
        if (0 <= k && i + j + k == n) {
          cout << j << ' ' << i << ' ' << k << endl;
          f = true;
          i = j = 1 << 29;
        }
      }
    }
    if (!f) cout << "-1 -1 -1" << endl;
  }
  
  return 0;
}
