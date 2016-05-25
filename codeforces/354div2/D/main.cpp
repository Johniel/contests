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


const int N = 1000 + 10;
char g[N][N];
int h, w;
int ti, tj;
int mi, mj;

const int U = 0;
const int R = 1;
const int D = 2;
const int L = 3;

char rot(char c)
{
  if (c == '+') return '+';

  if (c == '-') return '|';
  if (c == '|') return '-';

  if (c == '<') return '^';
  if (c == '>') return 'v';
  if (c == 'v') return '<';
  if (c == '^') return '>';

  if (c == 'L') return 'U';
  if (c == 'U') return 'R';
  if (c == 'R') return 'D';
  if (c == 'D') return 'L';

  if (c == '*') return '*';
}

bool valid(char c, int dir)
{
  if (c == '+') return true;

  if (c == '-' && (dir == R || dir == L)) return true;
  if (c == '|' && (dir == D || dir == U)) return true;

  if (c == '<' && dir == L) return true;
  if (c == '>' && dir == R) return true;
  if (c == 'v' && dir == D) return true;
  if (c == '^' && dir == U) return true;

  if (c == 'L' && dir != L) return true;
  if (c == 'R' && dir != R) return true;
  if (c == 'U' && dir != U) return true;
  if (c == 'D' && dir != D) return true;

  if (c == '*') return false;
  return false;
}

char rn(int i, int j, int r)
{
  char c = g[i][j];
  while (r--) c = rot(c);
  return c;
}

int opp(int dir)
{
  if (dir == R) return L;
  if (dir == L) return R;
  if (dir == U) return D;
  if (dir == D) return U;
}

struct S { int r, i, j; };

int cost[4][N][N];

int f(void)
{
  const int di[] = {-1, 0, +1, 0};
  const int dj[] = {0, +1, 0, -1};
  const int inf = 1 << 29;

  fill(&cost[0][0][0], &cost[4 - 1][N - 1][N - 1] + 1, inf);
  cost[0][ti][tj] = 0;  

  queue<S> q;
  for (q.push((S){0, ti, tj}); q.size(); q.pop()) {
    S curr = q.front();
    
    for (int d = 0; d < 4; ++d) {
      int ni = curr.i + di[d];
      int nj = curr.j + dj[d];
      int nr = curr.r;
      unless (0 <= ni && ni < h) continue;
      unless (0 <= nj && nj < w) continue;
      if (cost[nr][ni][nj] != inf) continue;
      if (0 &&curr.i == 0 && curr.j == 0 && curr.r == 3) {
        cout << "--" << endl;
        cout << rn(curr.i, curr.j, curr.r) << endl;
        cout << rn(ni, nj, curr.r) << endl;
        cout << opp(d) << endl;
        cout << "##" << endl;
      }
      if (valid(rn(curr.i, curr.j, curr.r), d) &&
          valid(rn(ni, nj, curr.r), opp(d))) {
        cost[nr][ni][nj] = cost[curr.r][curr.i][curr.j] + 1;
        q.push((S){nr, ni, nj});
      }
    }
    int nr = (curr.r + 1) % 4;
    if (cost[nr][curr.i][curr.j] == inf) {
      cost[nr][curr.i][curr.j] = cost[curr.r][curr.i][curr.j] + 1;
      q.push((S){nr, curr.i, curr.j});
    }
  }

  int mn = inf;
  for (int i = 0; i < 4; ++i) {
    mn = min(mn, cost[i][mi][mj]);
  }
  return mn == inf ? -1 : mn;
}

int main(int argc, char *argv[])
{
  while (scanf("%d %d\n", &h, &w) == 2) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        scanf("%c", &(g[i][j]));
      }
      scanf("\n");
    }

    // cout << h << ' ' << w << endl;
    // for (int i = 0; i < h; ++i) {
    //   for (int j = 0; j < w; ++j) {
    //     cout << g[i][j];
    //   }
    //   cout << endl;
    // }

    scanf("%d %d\n", &ti, &tj);
    scanf("%d %d\n", &mi, &mj);
    --ti;
    --tj;
    --mi;
    --mj;
    printf("%d\n", f());
  }
  return 0;
}
