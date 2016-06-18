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

int a, b, c;

string s, t;

const int N = 1000 + 2;
const int K = 11;
int memo[N][2][N][2][K];
const int inf = (1 << 28);

int rec(int i, int I, int j, int J, int k)
{
  if (k == c) {
    return 0;
  }

  if (i == s.size()) return -inf;
  if (j == t.size()) return -inf;

  int& ret = memo[i][I][j][J][k];
  if (ret != -1) return ret;
  
  int mx = -inf;

  if (I && J) {
    if (s[i] == t[j]) {
      mx = max(mx, rec(i + 1, true, j + 1, true, k) + 1);
      mx = max(mx, rec(i + 1, false, j + 1, false, k + 1) + 1);
    }
  } else if (I) {
    mx = max(mx, rec(i, true, j + 1, false, k));
  } else if (J) {
    mx = max(mx, rec(i + 1, false, j, true, k));
  } else {
    mx = max(mx, rec(i, true, j, true, k));
    mx = max(mx, rec(i + 1, false, j, false, k));
    mx = max(mx, rec(i, false, j + 1, false, k));    
  }
  return ret = mx;
}

int main(int argc, char *argv[])
{
  while (scanf("%d%d%d", &a, &b, &c) == 3) {
    char buff[1000 + 10];

    scanf("%s", buff);
    s = string(buff);

    scanf("%s", buff);
    t = string(buff);

    fill(&memo[0][0][0][0][0], &memo[N - 1][2 - 1][N - 1][2 - 1][K - 1] + 1, -1);
    printf("%d\n", rec(0, false, 0, false, 0));

    // break;
  }
  return 0;
}
