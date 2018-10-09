#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template<typename P, typename Q>
istream& operator >> (istream& is, pair<P, Q>& p)
{
  is >> p.first >> p.second;
  return is;
}

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

template<typename T>
istream& operator >> (istream& is, vector<T>& v)
{
  each (i, v) is >> i;
  return is;
}

struct C {
  lli x, y, z;
  lli operator () () { return abs(x) + abs(y) + abs(z); }
};
C operator + (C a, C b)
{
  a.x += b.x;
  a.y += b.y;
  a.z += b.z;
  return a;
}

bool operator < (C a, C b)
{
  return a.x + a.y + a.z < b.x + b.y + b.z;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    lli _x[n];
    lli _y[n];
    lli _z[n];
    for (int i = 0; i < n; ++i) {
      cin >> _x[i] >> _y[i] >> _z[i];
    }

    const lli inf = 1LL << 60;
    const int N = 1000 + 5;
    static C dp[N][N];

    lli x[n];
    lli y[n];
    lli z[n];
    
    lli mx = 0;
    for (int a = 0; a < 2; ++a) {
      for (int b = 0; b < 2; ++b) {
        for (int c = 0; c < 2; ++c) {
          copy(_x, _x + n, x);
          copy(_y, _y + n, y);
          copy(_z, _z + n, z);
          if (a) each (j, y) j *= -1;
          if (b) each (j, x) j *= -1;
          if (c) each (j, z) j *= -1;
          fill(&dp[0][0], &dp[N - 1][N - 1] + 1, C{-inf, -inf, -inf});
          dp[0][0] = C{0, 0, 0};
          for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
              dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
              dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (C){x[i], y[i], z[i]});
            }
          }
          mx = max(mx, dp[n][m]());
        }
      }
    }
    cout << mx << endl;
  }

  return 0;
}
