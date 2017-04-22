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

const int N = 2000 + 10;
vector<int> g[N];
int matched[N];
bool vis[N];

void add_edge(int src, int dst)
{
  g[src].push_back(dst);
  g[dst].push_back(src);
  return ;
}

bool rec(int curr)
{
  vis[curr] = true;
  each (next, g[curr]) {
    int m = matched[next];
    if (m < 0 || (!vis[m] && rec(m))) {
      matched[curr] = next;
      matched[next] = curr;
      return true;
    }
  }
  return false;
}


int matching(int n = N)
{
  int res = 0;
  fill(matched, matched + N, -1);
  for (int i = 0; i < n; ++i) {
    if (matched[i] < 0) {
      fill(vis, vis + N, false);
      res += rec(i);
    }
  }
  return res;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  cin >> tc;
  while (tc--) {
    fill(g, g + N, vector<int>());
    
    int n, R, O, Y, G, B, V;
    cin >> n >> R >> O >> Y >> G >> B >> V;
    map<int, char> m;
    int color[N];
    fill(color, color + N, 0);
    {
      const int r = (1 << 0);
      const int b = (1 << 1);
      const int y = (1 << 2);
      const int o = r | y;
      const int g = b | y;
      const int v = r | b;
      m[r] = 'R';
      m[b] = 'B';
      m[y] = 'Y';
      m[o] = 'O';
      m[g] = 'G';
      m[v] = 'V';
      int sum = 0;
      for (int i = 0; i < R; ++i, ++sum) color[sum] = r;
      for (int i = 0; i < Y; ++i, ++sum) color[sum] = y;
      for (int i = 0; i < B; ++i, ++sum) color[sum] = b;

      for (int i = 0; i < O; ++i, ++sum) color[sum] = o;
      for (int i = 0; i < G; ++i, ++sum) color[sum] = g;
      for (int i = 0; i < V; ++i, ++sum) color[sum] = v;
    }

    const int base = N / 2;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        unless (color[i] & color[j]) {
          add_edge(i, j + base);
        }
      }
    }

    int x = matching();
    // for (int i = 0; i < n; ++i) {
    //   int j = matched[i] - base;
    //   cout << make_pair(i, j) << ' ' << make_pair(m[color[i]], m[color[j]]) << endl;
    // }

    static int tc = 0;
    cout << "Case #" << ++tc << ": ";
    if (x != n) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      vector<int> v;
      for (int i = 0; v.size() < n; i = matched[i] - base) {
        v.push_back(i);
      }
      each (i, v) cout << m[color[i]] ; cout << endl;
    }
  }
  
  return 0;
}
