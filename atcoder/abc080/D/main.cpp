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

const int N = 1e5 * 2 + 10;
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
  int c;
  while (cin >> n >> c) {
    fill(g, g + N, vector<int>());
    vector<pair<int, int>> v[c];
    map<tuple<int, int, int>, int> name;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      int s, t, c;
      cin >> s >> t >> c;
      --c;
      v[c].push_back(make_pair(s, t));
      name[make_tuple(c, s, t)] = cnt++;
    }
    for (int i = 0; i < c; ++i) {
      sort(v[i].begin(), v[i].end()); 
    }

    for (int i = 0; i < c; ++i) {
      for (int j = 0; j + 1 < v[i].size(); ++j) {
        tuple<int, int, int> a = make_tuple(i, v[i][j].first, v[i][j].second);
        tuple<int, int, int> b = make_tuple(i, v[i][j + 1].first, v[i][j + 1].second);
        add_edge(name[a], name[b] + name.size());
      }
    }
    for (int i = 0; i < c; ++i) {
      for (int j = 0; j < v[i].size(); ++j) {
        const pair<int, int>& p = v[i][j];
        auto a = make_tuple(i, v[i][j].first, v[i][j].second);
        for (int k = 0; k < c; ++k) {
          if (i == k) continue;
          auto itr = lower_bound(v[k].begin(), v[k].end(), make_pair(p.second + 1, 0));
          if (itr != v[k].end()) {
            auto b = make_tuple(k, itr->first, itr->second);
            add_edge(name[a], name[b] + name.size());
          }
        }
      }
    }

    cout << n - matching() << endl;
  }
  
  return 0;
}
