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

struct edge {
  int to, cap, rev;
};

const int N = 200 + 10;
vector<int> g[N];

void add_edge(int src, int dst)
{
  g[src].push_back(dst);
  g[dst].push_back(src);
  return ;
}

int match[N];
int vis[N], x;
bool rec(int curr)
{
  vis[curr] = x;
  each (next, g[curr]) {
    int w = match[next];
    if (w < 0 || (vis[w] != x && rec(w))) {
      match[curr] = next;
      match[next] = curr;
      return true;
    }
  }
  return false;
}

int matching(int n = N)
{
  int res = 0;
  fill(match, match + N, -1);
  x = 1;
  fill(vis, vis + N, 0);
  for (int i = 0; i < n; ++i) {
    if (match[i] < 0) {
      res += rec(i);
      ++x;
    }
  }
  return res;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    fill(g, g + N, vector<int>());

    pair<int, int> b[n];
    pair<int, int> r[n];
    for (int i = 0; i < n; ++i) {
      cin >> r[i].first >> r[i].second;
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i].first >> b[i].second;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (r[i].first < b[j].first && r[i].second < b[j].second) {
          add_edge(i, j + n);
        }
      }
    }
    cout << matching() << endl;
  }

  return 0;
}
