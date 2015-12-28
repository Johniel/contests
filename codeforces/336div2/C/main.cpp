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

const int M = 1000000 + 10;
int p[M];
int l[M];
int edge[M];

int memo[M];
int rec(int curr)
{
  int &ret = memo[curr];
  if (ret != -1) return ret;
  if (edge[curr] == -1) return ret = 1;
  else return ret = 1 + rec(edge[curr]);
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    fill(p, p + M, 0);
    fill(edge, edge + M, -1);
    for (int i = 0; i < n; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      p[a] = b;
    }
    l[0] = -1;
    for (int i = 1; i < M; ++i) {
      if (0 < p[i - 1]) l[i] = i - 1;
      else l[i] = l[i - 1];
    }
    for (int i = 0; i < M; ++i) {
      if (p[i]) {
        edge[i] = l[max(0, i - p[i])];
      }
    }
    // for (int i = 0; i < M; ++i) if (0 < p[i]) cout << i << ' ' << edge[i] << endl;
    fill(memo, memo + M, -1);
    int mn = n;
    for (int i = 0; i < M; ++i) {
      if (p[i]) mn = min(mn, n - rec(i));
    }
    printf("%d\n", mn);
  }
  return 0;
}
