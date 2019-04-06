// atcoder/abc041/D/main.cpp
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
  int m;
  while (cin >> n >> m) {
    vector<pair<int, int>> v(m);
    cin >> v;
    each (i, v) {
      --i.first;
      --i.second;
    }

    const int N = 16 + 1;
    int x[N];
    fill(begin(x), end(x), 0);
    each (i, v) {
      x[i.second] |= (1 << i.first);
    }

    const int M = 1 << N;
    lli dp[M];
    fill(begin(dp), end(dp), 0);
    dp[0] = 1;
    for (int bit = 0; bit < (1 << n); ++bit) {
      for (int i = 0; i < n; ++i) {
        if ((bit & x[i]) == x[i] && (bit & (1 << i)) == 0) {
          dp[bit | (1 << i)] += dp[bit];
        }
      }
    }
    cout << dp[(1 << n) - 1] << endl;
  }

  return 0;
}
