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

const int N = 100000 + 10;
vector<int> g[N];
vector<int> h[N];

int memo1[N];
int rec1(int curr)
{
  int& ret = memo1[curr];
  if (ret != -1) return ret;
  int mx = 1;
  each (next, g[curr]) mx = max(mx, rec1(next) + 1);
  return ret = mx;
}

int memo2[N];
int rec2(int curr)
{
  int& ret = memo2[curr];
  if (ret != -1) return ret;
  int mx = 1;
  each (next, h[curr]) mx = max(mx, rec2(next) + 1);
  return ret = mx;
}

int main(int argc, char *argv[])
{
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    fill(g, g + N, vector<int>());
    fill(h, h + N, vector<int>());
    map<int, lli> deg;
    for (int i = 0; i < m; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      ++deg[a];
      ++deg[b];
      if (a < b) {
        g[a].push_back(b);
        h[b].push_back(a);
      } else {
        g[b].push_back(a);
        h[a].push_back(b);
      }
    }
    fill(memo1, memo1 + N, -1);
    fill(memo2, memo2 + N, -1);
    // for (int i = 1; i <= n; ++i) cout << "deg: " << i << " := " << deg[i] << ", " << rec1(i) << endl;
    lli mx = 0;
    for (int i = 1; i <= n; ++i) {      
      // mx = max(mx, rec1(i) * deg[i]);
      mx = max(mx, rec2(i) * deg[i]); 
    }
    printf("%lld\n", mx);
  }
  return 0;
}
