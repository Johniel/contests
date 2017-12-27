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

const int N = 1e5 + 5;
map<int, char> p;
vector<int> g[N];

int memo[N];

int rec(int curr) {
  int& ret = memo[curr];
  if (ret != -1) return ret;
  int mx = 0;
  each (next, g[curr]) {
    mx = max(mx, rec(next) + (p[curr] == 0 && p[next] == 1));
  }
  return ret = mx;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    fill(g, g + N, vector<int>());
    p.clear();
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      p[i] = x;
    }

    int deg[N];
    fill(deg, deg + N, 0);

    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      ++deg[b];
    }

    fill(memo, memo + N, -1);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      if (deg[i] == 0) {
        mx = max(mx, rec(i) + p[i]);
      }
    }
    cout << mx << endl;
  }
  
  return 0;
}
