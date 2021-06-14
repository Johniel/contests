#include <algorithm>
#include <complex>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()
#define each(i, c) FOR(i, c)

#define VAR(a) cout << #a << " : " << a << endl;
#define LOG()  cout << __LINE__ << ", " << __func__ << endl;

typedef long long int lli;

using namespace std;

const int H = 500 + 1;
const int W = 500 + 1;
int g[H][W];

int h, w;

struct S {
  int i, j;
  int t;
  S(int i_, int j_, int t_)
    : i(i_), j(j_), t(t_) {}
};
bool operator < (const S &a, const S &b)
{
  return a.t > b.t;
}

const int L = H * W + 6;
double l[L];

const int inf = 1 << 28;

int si, sj;
int ti, tj;

bool sssp(const double lim)
{
  static int cost[H][W];

  fill(&cost[0][0], &cost[H - 1][W], inf);

  cost[si][sj] = 0;

  priority_queue<S> q;

  const int di[] = {0, 0, -1, 1};
  const int dj[] = {-1, 1, 0, 0};

  for (q.push(S(si, sj, 0)); q.size(); ) {
    S cur = q.top();
    q.pop();
    if (cost[cur.i][cur.j] != cur.t) continue;
    if (cur.i == ti && cur.j == tj) return true;
    for (int d = 0; d < (int)4; ++d) {
      int ni = cur.i + di[d];
      int nj = cur.j + dj[d];
      int nt = cur.t + 1;
      if (ni < 0 || nj < 0) continue;
      if (h <= ni || w <= nj) continue;
      if (g[ni][nj] == '#') continue;
      if (cost[ni][nj] <= nt) continue;
      if (g[ni][nj] * l[nt] < lim) continue;
      cost[ni][nj] = nt;
      q.push(S(ni, nj, nt));
    }
  }
  return false;
}

int main(int argc, char *argv[])
{
  l[0] = 1;
  for (int i = 1; i < (int)L; ++i) {
    l[i] = l[i - 1] * 0.99;
  }

  while (scanf("%d %d\n", &h, &w) != EOF) {
    for (int i = 0; i < (int)h; ++i) {
      for (int j = 0; j < (int)w; ++j) {
        char c;
        scanf("%c", &c);
        g[i][j] = c;
        if (c == '#') {
        } else if (g[i][j] == 's') {
          si = i;
          sj = j;
          g[i][j] = inf;
        } if (g[i][j] == 'g') {
          ti = i;
          tj = j;
          g[i][j] = inf;
        } else {
          g[i][j] -= '0';
        }
      }
      scanf("\n");
    }

    double large = 11;
    double small = 0;
    for (int loop = 50; --loop; ) {
      double mid = (large + small) / 2.0;
      if (sssp(mid)) small = mid;
      else large = mid;
    }
    if (sssp(small)) printf("%.10lf\n", small);
    else puts("-1");
  }
  return 0;
}
