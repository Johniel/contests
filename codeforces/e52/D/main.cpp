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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    int g[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
      }
    }

    pair<int, int> src, dst;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (g[i][j] == 1) src = make_pair(i, j);
        if (g[i][j] == n * n) dst = make_pair(i, j);
      }
    }

    const int inf = 1 << 29;
    const int K = 0;
    const int B = 1;
    const int R = 2;

    vector<tuple<int, int, int>> v;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < 3; ++k) {
          v.push_back(make_tuple(i, j, k));
        }
      }
    }

    pair<int, int> h[n][n][3][n][n][3];
    fill(&h[0][0][0][0][0][0], &h[n - 1][n - 1][3 - 1][n - 1][n - 1][3 - 1] + 1, make_pair(inf, inf));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        h[i][j][K][i][j][K] = h[i][j][B][i][j][B] = h[i][j][R][i][j][R] = make_pair(0, 0);
        for (int a = 0; a < 3; ++a) {
          for (int b = 0; b < 3; ++b) {
            if (a != b) h[i][j][a][i][j][b] = make_pair(1, 1);
          }
        }
        vector<int> di;
        vector<int> dj;
        int len;
        for (int k = 0; k < 3; ++k) {
          if (k == K) {
            di = vector<int>({-2, -2, -1, -1, +1, +1, +2, +2});
            dj = vector<int>({-1, +1, -2, +2, -2, +2, -1, +1});
            len = 1;
          }
          if (k == B) {
            di = vector<int>({-1, -1, +1, +1});
            dj = vector<int>({-1, +1, -1, +1});
            len = n;
          }
          if (k == R) {
            di = vector<int>({0, 0, -1, +1});
            dj = vector<int>({-1, +1, 0, 0});
            len = n;
          }
          for (int d = 0; d < di.size(); ++d) {
            for (int l = 1; l <= len; ++l) {
              int ni = i + di[d] * l;
              int nj = j + dj[d] * l;
              unless  (0 <= ni && ni < n) continue;
              unless  (0 <= nj && nj < n) continue;
              h[i][j][k][ni][nj][k] = make_pair(1, 0);
            }
          }
        }
      }
    }

    auto add = [] (pair<int, int> a, pair<int, int> b) { return make_pair(a.first + b.first, a.second + b.second); };

    for (int k = 0; k < v.size(); ++k) {
      for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v.size(); ++j) {
          pair<int, int> x = h[get<0>(v[i])][get<1>(v[i])][get<2>(v[i])][get<0>(v[k])][get<1>(v[k])][get<2>(v[k])];
          pair<int, int> y = h[get<0>(v[k])][get<1>(v[k])][get<2>(v[k])][get<0>(v[j])][get<1>(v[j])][get<2>(v[j])];
          pair<int, int>& z = h[get<0>(v[i])][get<1>(v[i])][get<2>(v[i])][get<0>(v[j])][get<1>(v[j])][get<2>(v[j])];
          z = min(z, add(x, y));
        }
      }
    }

    map<int, pair<int, int>> m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        m[g[i][j]] = make_pair(i, j);
      }
    }
    vector<pair<int, int>> ord;
    each (i, m) ord.push_back(i.second);

    const int N = n * n;
    pair<int, int> dp[N][3];
    fill(&dp[0][0], &dp[N - 1][3 - 1] + 1, make_pair(inf, inf));
    dp[0][K] = dp[0][B] = dp[0][R] = make_pair(0, 0);
    for (int i = 0; i + 1 < N; ++i) {
      pair<int, int> x = ord[i];
      pair<int, int> y = ord[i + 1];
      for (int a = 0; a < 3; ++a) {
        for (int b = 0; b < 3; ++b) {
          pair<int, int> cost = h[x.first][x.second][a][y.first][y.second][b];
          dp[i + 1][b] = min(dp[i + 1][b], add(dp[i][a], cost));
        }
      }
    }

    pair<int, int> mn = make_pair(inf, inf);
    mn = min(mn, dp[N - 1][K]);
    mn = min(mn, dp[N - 1][B]);
    mn = min(mn, dp[N - 1][R]);
    cout << mn.first << ' ' << mn.second << endl;
  }

  return 0;
}
